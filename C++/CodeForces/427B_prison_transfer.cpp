#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, t, c;
  std::cin >> n >> t >> c;
  std::vector<int> prisoners(n);
  for (int i = 0; i < n; ++i) std::cin >> prisoners[i];

  int result = 0;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (prisoners[i] > t) {
      result += std::max(count - c + 1, 0);
      count = 0;
      continue;
    }
    ++count;
  }
  result += std::max(count - c + 1, 0);
  std::cout << result << '\n';

  return 0;
}
