/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <list>
#include <unordered_map>
#include <vector>

struct TwitterPost {
  int tweet_id;
  int user_id;
  uint64_t timestamp;

  bool operator<(const TwitterPost& rhs) const {
    return timestamp < rhs.timestamp;
  }
};

class User {
 public:
  static constexpr int kFeedCount = 10;

  explicit User(int id) : id_{id} {}

  void postTweet(const TwitterPost& post) {
    posts_.push_back(post);
    feed_.push_front(post);
    fanOut(post);
  }

  void pushFeed(const TwitterPost& post) { feed_.push_front(post); }

  void addFollowee(User& followee) {
    if (id_ == followee.id()) return;
    if (following_.contains(followee.id())) return;
    following_.emplace(followee.id(), followee);
    mergeRecentUserPostsIntoFeed(followee);
  }

  void addFollower(User& follower) {
    if (id_ == follower.id()) return;
    if (followers_.contains(follower.id())) return;
    followers_.emplace(follower.id(), follower);
  }

  void removeFollowee(int followee_id) {
    auto it = following_.find(followee_id);
    if (it == following_.end()) return;
    removeAllUserPostsFromFeed(it->second);
    following_.erase(it);
  }

  void removeFollower(int follower_id) {
    auto it = followers_.find(follower_id);
    if (it == followers_.end()) return;
    followers_.erase(it);
  }

  int id() const { return id_; }
  const std::vector<TwitterPost>& posts() const { return posts_; }
  const std::list<TwitterPost>& feed() const { return feed_; }

 private:
  void fanOut(const TwitterPost& post) {
    for (auto&& [_, follower] : followers_) {
      follower.get().pushFeed(post);
    }
  }

  void mergeRecentUserPostsIntoFeed(const User& followee) {
    const auto& posts = followee.posts();
    auto post_it = posts.rbegin();
    auto feed_it = feed_.begin();
    for (int i = 0; i < kFeedCount && post_it != posts.rend(); ++feed_it) {
      if (feed_it == feed_.end() || *feed_it < *post_it) {
        feed_it = feed_.insert(feed_it, *post_it++);
        ++i;
      }
    }
  }

  void removeAllUserPostsFromFeed(const User& followee) {
    auto feed_it = feed_.begin();
    while (feed_it != feed_.end()) {
      if (feed_it->user_id == followee.id()) {
        feed_it = feed_.erase(feed_it);
      } else {
        ++feed_it;
      }
    }
  }

  int id_;
  std::vector<TwitterPost> posts_;
  std::list<TwitterPost> feed_;
  std::unordered_map<int, std::reference_wrapper<User>> following_;
  std::unordered_map<int, std::reference_wrapper<User>> followers_;
};

class Twitter {
 public:
  void postTweet(int user_id, int tweet_id) {
    TwitterPost post{tweet_id, user_id, getTimestamp()};
    auto& user = getUser(user_id);
    user.postTweet(post);
  }

  std::vector<int> getNewsFeed(int user_id) {
    const auto& user = getUser(user_id);
    const auto& feed = user.feed();
    std::vector<int> result;
    result.reserve(User::kFeedCount);
    for (const auto& post : feed) {
      result.push_back(post.tweet_id);
      if (result.size() == User::kFeedCount) break;
    }
    return result;
  }

  void follow(int follower_id, int followee_id) {
    if (follower_id == followee_id) return;
    auto& follower = getUser(follower_id);
    auto& followee = getUser(followee_id);
    follower.addFollowee(followee);
    followee.addFollower(follower);
  }

  void unfollow(int follower_id, int followee_id) {
    if (follower_id == followee_id) return;
    auto& follower = getUser(follower_id);
    auto& followee = getUser(followee_id);
    follower.removeFollowee(followee_id);
    followee.removeFollower(follower_id);
  }

 private:
  uint64_t getTimestamp() const {
    static uint64_t timestamp = 0;
    return timestamp++;
  }

  User& getUser(int user_id) {
    return users_.try_emplace(user_id, User{user_id}).first->second;
  }

 private:
  std::unordered_map<int, User> users_;
};
// @lc code=end
