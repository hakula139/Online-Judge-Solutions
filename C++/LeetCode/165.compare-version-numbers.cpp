/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  int compareVersion(const std::string& version1, const std::string& version2) {
    auto revisions1 = splitVersion(version1);
    auto revisions2 = splitVersion(version2);
    auto end = std::max(revisions1.size(), revisions2.size());
    for (int i = 0; i < end; ++i) {
      auto rev1 = i < revisions1.size() ? revisions1[i] : 0;
      auto rev2 = i < revisions2.size() ? revisions2[i] : 0;
      if (rev1 < rev2) return -1;
      if (rev1 > rev2) return 1;
    }
    return 0;
  }

 private:
  std::vector<int> splitVersion(const std::string& version) {
    std::vector<int> result;
    for (auto it = version.begin(); it < version.end();) {
      auto sep_it = std::find(it, version.end(), '.');
      auto revision = std::stoi(std::string(it, sep_it));
      result.push_back(revision);
      it = sep_it < version.end() ? sep_it + 1 : version.end();
    }
    return result;
  }
};
// @lc code=end
