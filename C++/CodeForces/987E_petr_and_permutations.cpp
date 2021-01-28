#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> arr[i];
  bool count_is_odd = false;
  for (int i = 1; i <= n; ++i) {
    while (arr[i] != i) {
      std::swap(arr[i], arr[arr[i]]);
      count_is_odd = !count_is_odd;
    }
  }
  std::cout << ((n & 1) == count_is_odd ? "Petr\n" : "Um_nik\n");
  return 0;
}
