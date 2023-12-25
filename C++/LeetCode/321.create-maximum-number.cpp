/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <vector>

class Solution {
 public:
  std::vector<int> maxNumber(
      const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
    std::vector<int> result;
    int m = nums1.size(), n = nums2.size();
    int i_begin = std::max(k - n, 0), i_end = std::min(k, m);
    for (int i = i_begin; i <= i_end; ++i) {
      auto num1 = maxNumber(nums1, i);
      auto num2 = maxNumber(nums2, k - i);
      auto num = merge(num1, num2);
      if (compare(num, 0, result, 0) > 0) {
        std::swap(num, result);
      }
    }
    return result;
  }

 private:
  std::vector<int> maxNumber(const std::vector<int>& nums, int k) {
    std::vector<int> result;
    if (k == 0) return result;
    result.reserve(nums.size());
    int n_drops = nums.size() - k;
    for (auto num : nums) {
      for (; n_drops > 0 && result.size() && result.back() < num; --n_drops) {
        result.pop_back();
      }
      result.push_back(num);
    }
    for (; n_drops > 0; --n_drops) {
      result.pop_back();
    }
    return result;
  }

  std::vector<int> merge(
      const std::vector<int>& num1, const std::vector<int>& num2) {
    auto m = num1.size(), n = num2.size();
    std::vector<int> num;
    num.reserve(m + n);
    int i1 = 0, i2 = 0;
    while (i1 < m && i2 < n) {
      if (compare(num1, i1, num2, i2) > 0) {
        num.push_back(num1[i1++]);
      } else {
        num.push_back(num2[i2++]);
      }
    }
    std::copy(num1.begin() + i1, num1.end(), std::back_inserter(num));
    std::copy(num2.begin() + i2, num2.end(), std::back_inserter(num));
    return num;
  }

  int compare(const std::vector<int>& num1, int i1,
              const std::vector<int>& num2, int i2) {
    for (; i1 < num1.size() || i2 < num2.size(); ++i1, ++i2) {
      if (i1 == num1.size()) return -1;
      if (i2 == num2.size()) return 1;
      if (num1[i1] < num2[i2]) return -1;
      if (num1[i1] > num2[i2]) return 1;
    }
    return 0;
  }
};
// @lc code=end
