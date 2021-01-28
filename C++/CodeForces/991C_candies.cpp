#include <algorithm>
#include <cstdint>
#include <iostream>

int64_t total_num;

bool Check(int64_t k) {
  int64_t sum = 0;
  int64_t total = total_num;
  if (!k) return false;
  while (total > 0) {
    int64_t taken = std::min(k, total);
    sum += taken;
    total -= taken;
    total -= total / 10;
  }
  return sum >= ((total_num + 1) >> 1);
}

int64_t BinarySearch(int64_t low, int64_t high) {
  int64_t result = 1;
  while (low < high) {
    int64_t mid = low + ((high - low) >> 1);
    if (Check(mid)) {
      if (mid == 1 || !Check(mid - 1)) {
        result = mid;
        break;
      }
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (low == high) result = low;
  return result;
}

int main() {
  std::cin >> total_num;
  std::cout << BinarySearch(1, total_num) << '\n';
  return 0;
}
