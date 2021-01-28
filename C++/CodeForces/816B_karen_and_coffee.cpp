#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, k, q;
  std::cin >> n >> k >> q;
  const int max_temp = 200000;
  int lowest = 0;
  int highest = max_temp;
  std::vector<int> recipe(max_temp + 2);
  for (int i = 0; i < n; ++i) {
    int low, high;
    std::cin >> low >> high;
    ++recipe[low];
    --recipe[high + 1];
    lowest = std::min(low, lowest);
    highest = std::max(high, highest);
  }
  for (int i = lowest; i <= highest; ++i) recipe[i + 1] += recipe[i];
  for (int i = lowest - 1; i <= highest; ++i)
    recipe[i + 1] = recipe[i] + (recipe[i + 1] >= k ? 1 : 0);
  for (int i = 0; i < q; ++i) {
    int low, high;
    std::cin >> low >> high;
    std::cout << recipe[high] - recipe[low - 1] << '\n';
  }
  return 0;
}
