/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
#include <vector>

class Solution {
 public:
  TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
  }

 private:
  TreeNode* sortedArrayToBST(const std::vector<int>& nums, int begin, int end) {
    if (begin >= end) return nullptr;
    int mid = begin + (end - begin) / 2;
    return new TreeNode{
        nums[mid],
        sortedArrayToBST(nums, begin, mid),
        sortedArrayToBST(nums, mid + 1, end),
    };
  }
};
// @lc code=end
