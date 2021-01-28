#include <iomanip>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

static constexpr int kMaxSize = 123;
static constexpr int kStart = 100;
static constexpr int kBase = 1e6;
static constexpr int kWidth = 6;
static vector<vector<int>> catalan(kMaxSize, vector<int>(kMaxSize));

int main() {
  catalan[1][1] = 1;
  for (int i = 2; i <= 100; ++i) {
    // catalan[i] = catalan[i - 1] * (4i - 2) / (i + 1)
    for (int j = 1; j <= kStart; ++j) {
      if (!catalan[i - 1][j]) continue;
      catalan[i][j] += catalan[i - 1][j] * (4 * i - 2);
      catalan[i][j + 1] += catalan[i][j] / kBase;
      catalan[i][j] %= kBase;
    }
    for (int j = kStart; j >= 1; --j) {
      if (!catalan[i][j]) continue;
      int temp = catalan[i][j] % (i + 1);
      catalan[i][j - 1] += temp * kBase;
      catalan[i][j] /= (i + 1);
    }
  }

  int n;
  while (cin >> n) {
    int start;
    for (start = kStart; !catalan[n][start]; --start) {
    }
    cout << catalan[n][start--];
    for (int i = start; i > 0; --i) {
      cout << std::setw(kWidth) << std::setfill('0') << std::right
           << catalan[n][i];
    }
    cout << '\n';
  }
  return 0;
}
