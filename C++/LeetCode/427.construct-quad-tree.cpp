/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

struct Node {
  bool val = false;
  bool isLeaf = false;
  Node* topLeft = nullptr;
  Node* topRight = nullptr;
  Node* bottomLeft = nullptr;
  Node* bottomRight = nullptr;
};

// @lc code=start
#include <array>
#include <vector>

const std::array kLeaves{
    new Node{false, true},
    new Node{true, true},
};

class Solution {
 public:
  Node* construct(const std::vector<std::vector<int>>& grid) {
    return construct(grid, 0, 0, grid.size());
  }

 private:
  Node* construct(const std::vector<std::vector<int>>& grid, int i, int j,
                  int n) {
    if (n == 1) {
      return kLeaves[grid[i][j]];
    }

    n >>= 1;
    auto tl = construct(grid, i, j, n);
    auto tr = construct(grid, i, j + n, n);
    auto bl = construct(grid, i + n, j, n);
    auto br = construct(grid, i + n, j + n, n);

    if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
      if (!tl->val && !tr->val && !bl->val && !br->val) {
        return kLeaves[0];
      }
      if (tl->val && tr->val && bl->val && br->val) {
        return kLeaves[1];
      }
    }
    return new Node{false, false, tl, tr, bl, br};
  }
};
// @lc code=end
