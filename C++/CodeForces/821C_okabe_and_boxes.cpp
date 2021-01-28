#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::stack;
using std::string;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int end = n << 1;
  int count = 0;
  int cur = 1;
  stack<int> box_stack;
  for (int i = 0; i < end; ++i) {
    string op;
    cin >> op;
    if (op[0] == 'a') {  // op == "add"
      int box;
      cin >> box;
      box_stack.push(box);
    } else {  // op == "remove"
      if (!box_stack.empty()) {
        if (box_stack.top() == cur) {
          box_stack.pop();
        } else {
          stack<int>().swap(box_stack);  // clear box_stack
          ++count;
        }
      }
      ++cur;
    }
  }
  cout << count << '\n';
  return 0;
}
