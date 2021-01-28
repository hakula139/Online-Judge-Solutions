#include <iostream>
#include <map>
#include <utility>

using std::cin;
using std::cout;
using std::map;

const int kMaxGrade = 1e9;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n) {
    if (!n) break;
    map<int, int> id_map;
    id_map[kMaxGrade] = 1;
    while (n--) {
      int id, grade;
      cin >> id >> grade;
      cout << id << ' ';
      id_map[grade] = id;
      auto pos = id_map.find(grade);
      if (pos == id_map.begin()) {
        cout << (++pos)->second;
      } else {
        auto prev = std::prev(pos, 1);
        auto next = std::next(pos, 1);
        cout << (pos->first - prev->first <= next->first - pos->first
                     ? prev->second
                     : next->second);
      }
      cout << '\n';
    }
  }
  return 0;
}
