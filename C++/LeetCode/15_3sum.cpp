#include <algorithm>
#include <tuple>
#include <vector>

using std::sort;
using std::tuple;
using std::vector;

class Solution {
 public:
  vector<vector<int>> threeSum(const vector<int>& nums) {
    vector<vector<int>> triplets;
    if (nums.size() < 3) return triplets;

    auto sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    auto k_end = sorted_nums.end() - 2;
    for (auto k = sorted_nums.begin(); k < k_end && *k <= 0; ++k) {
      for (auto [i, j] = tuple{k + 1, sorted_nums.end() - 1}; i < j; ++i, --j) {
        while (i != j && *i + *j + *k != 0) {
          while (i != j && *i + *j + *k < 0) ++i;
          while (i != j && *i + *j + *k > 0) --j;
        }
        if (i == j) break;
        triplets.push_back({*i, *j, *k});
        while (i != j && *i == *(i + 1)) ++i;
        while (i != j && *j == *(j - 1)) --j;
      }
      while (k < k_end && *k == *(k + 1)) ++k;
    }
    return triplets;
  }
};
