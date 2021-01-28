#include <algorithm>
#include <iostream>
#include <map>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::map<int, int> points;
    while (n--) {
      int start, end;
      std::cin >> start >> end;
      ++points[start];
      --points[end + 1];
    }
    int max = 0;
    int cnt = 0;
    for (const auto& i : points) {
      cnt += i.second;
      max = std::max(cnt, max);
    }
    std::cout << max << '\n';
  }
  return 0;
}
