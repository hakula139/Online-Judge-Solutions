#include <cstdint>
#include <iostream>
#include <vector>

using std::abs;
using std::cin;
using std::cout;
using std::vector;

constexpr int kMaxSize = 2019;

struct City {
    City() : x(0), y(0), c(0), k(0) {}
    int64_t x, y;
    int64_t c, k;
};

vector<City>            city(kMaxSize);
vector<vector<int64_t>> cost(kMaxSize, vector<int64_t>(kMaxSize, INT64_MAX));
vector<int>             visited(kMaxSize);
vector<int>             pre(kMaxSize);
int                     n;

int64_t Prim() {
    int64_t result = 0;
    visited[0]     = 1;
    for (int i = 1; i <= n; ++i) {
        int64_t cost_min = INT64_MAX;
        int     v        = 0;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && cost[0][j] < cost_min) {
                cost_min = cost[0][j];
                v        = j;
            }
        }
        if (cost_min == INT64_MAX) return -1;
        visited[v] = 1;
        result += cost_min;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && cost[v][j] < cost[0][j]) {
                cost[0][j] = cost[v][j];
                pre[j]     = v;
            }
        }
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> city[i].x >> city[i].y;
    for (int i = 1; i <= n; ++i) cin >> city[i].c;
    for (int i = 1; i <= n; ++i) cin >> city[i].k;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            auto& u        = city[i];
            auto& v        = city[j];
            auto  distance = abs(u.x - v.x) + abs(u.y - v.y);
            cost[i][j] = cost[j][i] = (u.k + v.k) * distance;
        }
    }
    for (int i = 1; i <= n; ++i) cost[0][i] = cost[i][0] = city[i].c;
    cout << Prim() << '\n';
    vector<int> station;
    for (int i = 1; i <= n; ++i) {
        if (!pre[i]) station.push_back(i);
    }
    int size = station.size();
    cout << size << '\n';
    for (const auto& i : station) cout << i << ' ';
    cout << '\n';
    cout << n - size << '\n';
    // for (int i = 1; i <= n; ++i) cout << pre[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= n; ++j) cout << cost[i][j] << "\t\t";
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (pre[i] == j || pre[j] == i) cout << i << ' ' << j << '\n';
        }
    }
    return 0;
}
