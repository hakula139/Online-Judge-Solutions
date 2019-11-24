#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

static constexpr int kMaxSize = 233333;
static vector<int>   parent(kMaxSize);
static vector<int>   color(kMaxSize);

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) cin >> parent[i];
    for (int i = 1; i <= n; ++i) cin >> color[i];
    int result = 1;
    for (int i = 2; i <= n; i++)
        if (color[i] != color[parent[i]]) ++result;
    cout << result << '\n';
    return 0;
}
