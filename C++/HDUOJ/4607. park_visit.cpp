#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

static const int           kMaxSize = 1e5 + 233;
static vector<vector<int>> nodes(kMaxSize);
static vector<int>         distance(kMaxSize);

void DFS(int cur, int pre) {
    int size = nodes[cur].size();
    for (int i = 0; i < size; ++i) {
        int next = nodes[cur][i];
        if (next == pre) continue;
        distance[next] = distance[cur] + 1;
        DFS(next, cur);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        nodes.clear();
        distance.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) nodes[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }

        distance[1] = 0;
        DFS(1, 0);
        int start        = 0;
        int max_distance = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] > distance[start]) start = i;
        }
        distance[start] = 0;
        DFS(start, 0);
        int max_i = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] > distance[max_i]) max_i = i;
        }
        max_distance = distance[max_i];

        while (m--) {
            int k;
            cin >> k;
            cout << (k <= max_distance ?
                         k - 1 :
                         max_distance + (k - max_distance - 1) * 2)
                 << '\n';
        }
    }
    return 0;
}
