#include <vector>

using std::vector;

class Solution {
 public:
  int numIslands(const vector<vector<char>>& grid) {
    row_size_ = grid.size();
    col_size_ = row_size_ ? grid[0].size() : 0ull;
    grid_ = grid;
    checked_ = vector<vector<bool>>(row_size_, vector<bool>(col_size_, false));

    auto result = 0;
    for (auto i = 0; i < row_size_; ++i) {
      for (auto j = 0; j < col_size_; ++j) {
        if (grid[i][j] == '1' && !checked_[i][j]) {
          SearchLand(i, j);
          ++result;
        }
      }
    }
    return result;
  }

 private:
  int row_size_;
  int col_size_;
  vector<vector<char>> grid_;
  vector<vector<bool>> checked_;

  void SearchLand(int i, int j) {
    if (i < 0 || i >= row_size_) return;
    if (j < 0 || j >= col_size_) return;
    if (checked_[i][j]) return;
    if (grid_[i][j] == '0') return;
    checked_[i][j] = true;
    SearchLand(i - 1, j);
    SearchLand(i + 1, j);
    SearchLand(i, j - 1);
    SearchLand(i, j + 1);
  }
};
