#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

int main() {
  int p;
  cin >> p;
  while (p--) {
    int case_num, m;
    cin >> case_num >> m;
    cout << case_num << ' ' << ((m + 1) >> 1) << '\n';
    priority_queue<int> top_heap;     // max heap
    priority_queue<int> bottom_heap;  // min heap
    vector<int> result;
    for (int i = 1; i <= m; ++i) {
      int num;
      cin >> num;
      top_heap.push(num);
      bottom_heap.push(-num);
      if (!(i & 1)) continue;
      while (top_heap.top() != -bottom_heap.top()) {
        int top_max = top_heap.top();
        top_heap.pop();
        int bottom_min = -bottom_heap.top();
        bottom_heap.pop();
        top_heap.push(bottom_min);
        bottom_heap.push(-top_max);
      }
      // cout << top_heap.top() << ' ';
      // if (((i + 1) >> 1) % 10 == 0 || i == m) cout << '\n';
      result.push_back(top_heap.top());
    }
    int size = result.size();
    for (int i = 1; i <= size; ++i) {
      cout << result[i - 1] << ((i % 10 == 0 || i == size) ? '\n' : ' ');
    }
  }
  return 0;
}
