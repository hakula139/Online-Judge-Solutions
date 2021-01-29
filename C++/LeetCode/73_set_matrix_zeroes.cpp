#include <set>
#include <vector>

using std::set;
using std::vector;

// 32 ms, 13.2 MB
class Solution1 {
 public:
  void setZeroes(vector<vector<int>>& matrix) {  // NOLINT(runtime/references)
    set<int> row_pos;
    set<int> col_pos;

    auto row_count = matrix.size();
    auto col_count = row_count ? matrix.front().size() : 0ull;

    for (auto i = 0; i < row_count; ++i) {
      for (auto j = 0; j < col_count; ++j) {
        if (!matrix[i][j]) {
          row_pos.insert(i);
          col_pos.insert(j);
        }
      }
    }

    for (auto row : row_pos) {
      for (auto j = 0; j < col_count; ++j) matrix[row][j] = 0;
    }
    for (auto col : col_pos) {
      for (auto i = 0; i < row_count; ++i) matrix[i][col] = 0;
    }
  }
};

// 8 ms, 13.2 MB
class Solution2 {
 public:
  void setZeroes(vector<vector<int>>& matrix) {  // NOLINT(runtime/references)
    bool first_row_is_zero = false;
    bool first_col_is_zero = false;

    auto row_count = matrix.size();
    auto col_count = row_count ? matrix.front().size() : 0ull;

    for (auto i = 0; i < row_count; ++i) {
      if (!matrix[i][0]) {
        first_col_is_zero = true;
        break;
      }
    }
    for (auto j = 0; j < col_count; ++j) {
      if (!matrix[0][j]) {
        first_row_is_zero = true;
        break;
      }
    }

    for (auto i = 1; i < row_count; ++i) {
      for (auto j = 1; j < col_count; ++j) {
        if (!matrix[i][j]) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (auto i = 1; i < row_count; ++i) {
      if (!matrix[i][0]) ClearRow(&matrix, i, col_count);
    }
    for (auto j = 1; j < col_count; ++j) {
      if (!matrix[0][j]) ClearColumn(&matrix, j, row_count);
    }
    if (first_row_is_zero) ClearRow(&matrix, 0, col_count);
    if (first_col_is_zero) ClearColumn(&matrix, 0, row_count);
  }

  void ClearRow(vector<vector<int>>* p_matrix, int row, int col_count) {
    for (auto j = 0; j < col_count; ++j) (*p_matrix)[row][j] = 0;
  }

  void ClearColumn(vector<vector<int>>* p_matrix, int col, int row_count) {
    for (auto i = 0; i < row_count; ++i) (*p_matrix)[i][col] = 0;
  }
};
