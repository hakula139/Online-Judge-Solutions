#include <tuple>
#include <vector>

using std::tuple;
using std::vector;

class Solution {
 public:
  bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    int row_size = matrix.size();
    int col_size = row_size ? matrix[0].size() : 0;
    for (auto [i, j] = tuple{0, col_size - 1}; i < row_size && j >= 0;) {
      if (target == matrix[i][j]) return true;
      target < matrix[i][j] ? --j : ++i;
    }
    return false;
  }
};
