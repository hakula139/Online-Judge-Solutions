#include <cmath>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int sqrt_n = sqrt(n);
  for (int i = sqrt_n; i > 0; --i)
    for (int j = i; j <= n; j += sqrt_n) std::cout << j << ' ';
  std::cout << '\n';
  return 0;
}
