#include <iostream>
#include <limits>
#include <string>

template <class It>
void Encrypt(It i) {
  if ((*i >= 'A' && *i <= 'Y') || (*i >= 'a' && *i <= 'y'))
    *i += 1;
  else if (*i == 'Z' || *i == 'z')
    *i -= 'Z' - 'A';
}

int main() {
  size_t n;
  std::cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string password;
  for (size_t i = 0; i < n; ++i) {
    std::getline(std::cin, password);
    for (auto i = password.begin(); i != password.end(); ++i) {
      Encrypt(i);
    }
    std::cout << password << "\n";
  }

  return 0;
}
