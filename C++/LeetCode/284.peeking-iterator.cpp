/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

#include <vector>

class Iterator {
 public:
  explicit Iterator(const std::vector<int>& nums);
  Iterator(const Iterator& iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;

 private:
  struct Data* data;
};

// @lc code=start
#include <optional>

class PeekingIterator : public Iterator {
 public:
  explicit PeekingIterator(const std::vector<int>& nums) : Iterator{nums} {
    if (Iterator::hasNext()) {
      next_val_ = Iterator::next();
    }
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() const { return next_val_.value(); }

  // Returns the next element in the iteration.
  int next() {
    auto val = peek();
    if (Iterator::hasNext()) {
      next_val_ = Iterator::next();
    } else {
      next_val_ = {};
    }
    return val;
  }

  // Returns true if the iteration has more elements.
  bool hasNext() const { return next_val_.has_value(); }

 private:
  std::optional<int> next_val_;
};
// @lc code=end
