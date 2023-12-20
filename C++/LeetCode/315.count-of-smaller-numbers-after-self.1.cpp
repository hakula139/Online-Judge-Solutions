/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> countSmaller(const std::vector<int>& nums) {
    auto n = nums.size();
    std::vector<std::pair<int, int>> indexed_nums(n);
    for (int i = 0; i < n; ++i) {
      indexed_nums[i] = {nums[i], i};
    }
    std::vector<int> inversions(n);
    mergeSort(indexed_nums, 0, n, inversions);
    return inversions;
  }

 private:
  void mergeSort(std::vector<std::pair<int, int>>& nums, int begin, int end,
                 std::vector<int>& inversions) {
    if (begin >= end - 1) return;
    int mid = begin + (end - begin) / 2;
    mergeSort(nums, begin, mid, inversions);
    mergeSort(nums, mid, end, inversions);

    std::vector<std::pair<int, int>> sorted_nums;
    sorted_nums.reserve(end - begin);
    int n_inversions = 0;
    int i = begin, j = mid;
    while (i < mid && j < end) {
      if (nums[i].first <= nums[j].first) {
        inversions[nums[i].second] += n_inversions;
        sorted_nums.emplace_back(std::move(nums[i++]));
      } else {
        ++n_inversions;
        sorted_nums.emplace_back(std::move(nums[j++]));
      }
    }
    while (i < mid) {
      inversions[nums[i].second] += n_inversions;
      sorted_nums.emplace_back(std::move(nums[i++]));
    }
    std::move(sorted_nums.begin(), sorted_nums.end(), nums.begin() + begin);
  }
};
// @lc code=end
