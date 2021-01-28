#include <cstdint>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

int main() {
  int n;
  cin >> n;
  priority_queue<uint64_t, vector<uint64_t>, std::greater<uint64_t>> min_heap;
  if (!(n & 1)) min_heap.push(0);
  for (int i = 0; i < n; ++i) {
    int cnt;
    cin >> cnt;
    min_heap.push(cnt);
  }
  uint64_t result = 0;
  while (min_heap.size() > 1) {
    uint64_t temp = min_heap.top();
    min_heap.pop();
    temp += min_heap.top();
    min_heap.pop();
    temp += min_heap.top();
    min_heap.pop();
    result += temp;
    min_heap.push(temp);
  }
  cout << result << '\n';
  return 0;
}
