#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

constexpr int kMaxEnd = 10000;

// 36 ms, 31.1 MB, O(n)
class Solution1 {
 public:
  vector<vector<int>> merge(const vector<vector<int>>& intervals) {
    auto size = kMaxEnd + 2;
    vector<int> timetable(size);
    vector<int> singular(size);
    for (const auto& interval : intervals) {
      if (interval[0] == interval[1]) {
        ++singular[interval[0]];
      } else {
        ++timetable[interval[0]];
        --timetable[interval[1]];
      }
    }

    vector<vector<int>> result;
    auto start = -1;
    for (auto i = 0; i <= kMaxEnd; ++i) {
      timetable[i + 1] += timetable[i];
      if (start == -1) {
        if (timetable[i]) {
          start = i;
        } else if (singular[i]) {
          result.push_back({i, i});
        }
      } else if (!timetable[i]) {
        result.push_back({start, i});
        start = -1;
      }
    }
    return result;
  }
};

// 12 ms, 14.2 MB, O(n log(n))
class Solution2 {
 public:
  // NOLINTNEXTLINE(runtime/references)
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    for (const auto& interval : intervals) {
      if (result.empty() || result.back()[1] < interval[0]) {
        result.push_back(interval);
      } else if (interval[1] > result.back()[1]) {
        result.back()[1] = interval[1];
      }
    }
    return result;
  }
};
