#include <iostream>
#include <string>
#include <vector>

class KmpNextArray {
 public:
  void Init(const std::string& pattern) {
    next_array_.clear();
    next_array_.push_back(-1);
    size_t p_len_ = pattern.length();
    int prefix_i_ = -1;
    int postfix_i_ = 0;
    while (postfix_i_ < p_len_) /* one more step here */ {
      if (prefix_i_ == -1 || pattern[prefix_i_] == pattern[postfix_i_]) {
        ++prefix_i_, ++postfix_i_;
        // pattern[prefix_i_] != pattern[postfix_i_]
        //     ? next_array_.push_back(prefix_i_)
        //     : next_array_.push_back(next_array_[prefix_i_]);
        next_array_.push_back(prefix_i_);
      } else {
        prefix_i_ = next_array_[prefix_i_];
      }
    }
    // Print();
  }

  int Next(int i) {
    if (i < 0 || i >= next_array_.size()) return -1;
    return next_array_[i];
  }

  void Print() {
    std::cout << "The current KMP next_array is:\n";
    for (auto&& i : next_array_) std::cout << i << ' ';
    std::cout << '\n';
  }

 protected:
  std::vector<int> next_array_;
};

int main() {
  KmpNextArray next_array;
  std::string str;
  size_t str_len = 0;
  int count = 1;
  while (std::cin >> str_len) {
    if (!str_len) break;
    std::cin >> str;
    next_array.Init(str);
    std::cout << "Test case #" << count++ << '\n';
    for (size_t i = 2; i <= str_len; ++i) {
      size_t period_size = i - next_array.Next(i);
      if (!(i % period_size) && next_array.Next(i)) {
        std::cout << i << ' ' << i / period_size << '\n';
      }
    }
    std::cout << '\n';
  }
  return 0;
}
