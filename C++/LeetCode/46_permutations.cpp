#include <algorithm>
#include <deque>
#include <vector>

using std::deque;
using std::swap;
using std::vector;

class Solution {
 public:
  vector<vector<int>> permute(const vector<int>& nums) {
    deque<vector<int>> result{{}};
    for (auto num : nums) {
      for (auto size = result.size(); size; --size) {
        vector<int> cur = result.front();
        result.pop_front();
        cur.push_back(num);
        result.push_back(cur);
        for (auto i = cur.size() - 1; i; --i) {
          swap(cur[i], cur[i - 1]);
          result.push_back(cur);
        }
      }
    }
    return vector<vector<int>>(result.begin(), result.end());
  }
};
