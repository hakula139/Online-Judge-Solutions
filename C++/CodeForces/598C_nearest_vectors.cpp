#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::get;
using std::make_tuple;
using std::sort;
using std::tuple;
using std::vector;

const long double kPi = acos(-1);

int main() {
  int n;
  cin >> n;
  vector<tuple<long double, int>> angle;
  for (int i = 1; i <= n; ++i) {
    long double x, y;
    cin >> x >> y;
    long double cur_angle = atan2(y, x);
    angle.push_back(make_tuple(cur_angle, i));
  }
  auto cmp_angle = [](const auto& tuple1, const auto& tuple2) {
    return get<0>(tuple1) < get<0>(tuple2);
  };
  sort(angle.begin(), angle.end(), cmp_angle);
  long double min_angle = 4;
  long double angle_dif;
  int a = 1, b = 2;
  for (int i = 0; i < n - 1; ++i) {
    angle_dif = get<0>(angle[i + 1]) - get<0>(angle[i]);
    if (angle_dif < min_angle) {
      min_angle = angle_dif;
      a = get<1>(angle[i]);
      b = get<1>(angle[i + 1]);
    }
  }
  angle_dif = 2 * kPi + get<0>(angle[0]) - get<0>(angle[n - 1]);
  if (angle_dif < min_angle) {
    min_angle = angle_dif;
    a = get<1>(angle[0]);
    b = get<1>(angle[n - 1]);
  }
  cout << a << ' ' << b << '\n';
  return 0;
}
