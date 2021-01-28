#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {
  int n;
  cin >> n;
  vector<int> u(n), v(n), color(n + 1);
  for (int i = 1; i < n; i++) cin >> u[i] >> v[i];
  for (int i = 1; i <= n; i++) cin >> color[i];

  int sum = 0;
  vector<int> cnt(n + 1);
  for (int i = 1; i < n; ++i) {
    if (color[u[i]] == color[v[i]]) continue;
    ++sum, ++cnt[u[i]], ++cnt[v[i]];
  }
  int i;
  for (i = 1; i <= n; i++) {
    if (cnt[i] == sum) {
      cout << "YES\n" << i << '\n';
      break;
    }
  }
  if (i > n) cout << "NO\n";
  return 0;
}
