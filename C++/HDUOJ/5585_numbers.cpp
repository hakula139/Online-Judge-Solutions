#include <iostream>
#include <string>

int main() {
  std::string n;
  while (std::cin >> n) {
    int len = n.size();
    if (!((n[len - 1] - '0') % 2) || !((n[len - 1] - '0') % 5)) {
      std::cout << "YES\n";
      continue;
    }
    int sum = 0;
    for (int i = 0; i < len; ++i) sum += n[i] - '0';
    std::cout << (sum % 3 ? "NO\n" : "YES\n");
  }
  return 0;
}
