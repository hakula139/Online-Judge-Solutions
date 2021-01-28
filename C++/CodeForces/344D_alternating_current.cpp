#include <iostream>
#include <stack>

int main() {
  std::stack<int> wires;
  char wire;
  while (std::cin >> wire) {
    if (wire == '\n') break;
    if (!wires.empty() && wires.top() == wire)
      wires.pop();
    else
      wires.push(wire);
  }
  std::cout << (wires.empty() ? "Yes\n" : "No\n");
  return 0;
}
