#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

// 8 ms, 10.4 MB
class Solution1 {
 public:
  int findKthLargest(const vector<int>& nums, int k) {
    priority_queue<int> heap;
    for (auto num : nums) heap.push(num);
    while (--k) heap.pop();
    return heap.top();
  }
};

// 16 ms, 10.1 MB
class Solution2 {
 public:
  int findKthLargest(const vector<int>& nums, int k) {
    priority_queue<int> heap;
    auto size = nums.size();
    for (auto i = 0; i < k && i < size; ++i) {
      heap.push(-nums[i]);
    }
    for (auto i = k; i < size; ++i) {
      if (-nums[i] < heap.top()) {
        heap.pop();
        heap.push(-nums[i]);
      }
    }
    return -heap.top();
  }
};
