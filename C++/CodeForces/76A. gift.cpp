#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::set;
using std::sort;
using std::swap;
using std::vector;

constexpr int kMaxSize = 50233;

struct Edge {
    Edge() : from(0), to(0), g(0), s(0) {}
    Edge(int _from, int _to, int _g, int _s)
        : from(_from), to(_to), g(_g), s(_s) {}
    int     from, to;
    int64_t g, s;
};

vector<int>  parent(kMaxSize);
vector<Edge> edge(kMaxSize);
vector<int>  rank(kMaxSize);
int          n, m;
int64_t      g, s;

void Init() {
    for (int i = 1; i <= n; ++i) parent[i] = i;
}

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int p_x = Find(x);
    int p_y = Find(y);
    if (rank[x] < rank[y]) {
        parent[p_x] = p_y;
    } else {
        parent[p_y] = p_x;
        if (rank[x] == rank[y]) ++rank[y];
    }
}

bool IsConnected(int x, int y) { return Find(x) == Find(y); }

int64_t Kruskal() {
    int64_t      result = INT64_MAX;
    vector<Edge> mst(kMaxSize);
    int          total = 0;
    for (int i = 0; i < m; ++i) {
        Init();
        mst[total++] = edge[i];
        for (int j = total - 1; j >= 1; --j)
            if (mst[j].s < mst[j - 1].s) swap(mst[j], mst[j - 1]);
        int64_t g_max = 0, s_max = 0;
        int     size = 0;
        for (int j = 0; j < total; ++j) {
            auto& e = mst[j];
            if (IsConnected(e.from, e.to)) continue;
            mst[size++] = e;
            g_max       = max(g_max, e.g);
            s_max       = max(s_max, e.s);
            Union(e.from, e.to);
            if (size == n - 1) break;
        }
        if (size == n - 1) result = min(result, g_max * g + s_max * s);
        total = size;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> g >> s;
    for (int i = 0; i < m; ++i)
        cin >> edge[i].from >> edge[i].to >> edge[i].g >> edge[i].s;
    sort(edge.begin(), edge.begin() + m, [](const Edge& x, const Edge& y) {
        if (x.g != y.g) return x.g < y.g;
        return x.s < y.s;
    });
    int64_t result = Kruskal();
    cout << (result == INT64_MAX ? -1 : result) << '\n';
    return 0;
}
