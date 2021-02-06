#include <vector>

using std::vector;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    unique_paths_ = vector<vector<int>>(m + 1, vector<int>(n + 1));
    unique_paths_[1][1] = 1;
    return UniquePaths(m, n);
  }

 private:
  vector<vector<int>> unique_paths_;

  int UniquePaths(int m, int n) {
    if (m > 1) {
      auto cache = unique_paths_[m - 1][n];
      unique_paths_[m][n] += cache ? cache : UniquePaths(m - 1, n);
    }
    if (n > 1) {
      auto cache = unique_paths_[m][n - 1];
      unique_paths_[m][n] += cache ? cache : UniquePaths(m, n - 1);
    }
    return unique_paths_[m][n];
  }
};
