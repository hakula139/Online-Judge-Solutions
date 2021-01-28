#include <iostream>

int count = 0;

void StackSequenceCount(int in, int out) {
  if (!out) {
    count++;
  } else if (!in) {
    StackSequenceCount(in + 1, out - 1);
  } else {
    StackSequenceCount(in + 1, out - 1);
    StackSequenceCount(in - 1, out);
  }
}

int main() {
  int n;
  std::cin >> n;
  StackSequenceCount(0, n);
  std::cout << count << '\n';
  return 0;
}
