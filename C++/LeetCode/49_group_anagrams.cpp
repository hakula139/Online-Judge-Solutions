#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::sort;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, int> group_index;
    vector<vector<string>> result;
    for (const auto& str : strs) {
      string hash = str;
      sort(hash.begin(), hash.end());
      if (!group_index.count(hash)) {
        group_index[hash] = result.size();
        result.push_back({});
      }
      result[group_index[hash]].push_back(str);
    }
    return result;
  }
};
