#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::vector;

constexpr int kMaxSize = 2e5 + 233;

struct Edge {
  Edge() : from(0), to(0), cost(INT64_MAX) {}
  Edge(int _from, int _to, int64_t _cost) : from(_from), to(_to), cost(_cost) {}
  bool operator<(const Edge& that) const { return cost < that.cost; }
  int from, to;
  int64_t cost;
};

struct Node {
  Node() : id(0), cost(INT64_MAX) {}
  bool operator<(const Node& that) const { return cost < that.cost; }
  int id;
  int64_t cost;
};

vector<Node> a(kMaxSize);
vector<int> parent(kMaxSize);
vector<int> rank(kMaxSize);
vector<Edge> e;
int n, m;

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
  int64_t result = 0;
  int total = 0;
  for (const auto& edge : e) {
    if (IsConnected(edge.from, edge.to)) continue;
    Union(edge.from, edge.to);
    result += edge.cost;
    ++total;
    if (total == n - 1) break;
  }
  return total == n - 1 ? result : -1;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    a[i].id = parent[i] = i;
    cin >> a[i].cost;
  }
  for (int i = 0; i < m; ++i) {
    int from, to;
    int64_t cost;
    cin >> from >> to >> cost;
    e.push_back({from, to, cost});
  }
  sort(a.begin() + 1, a.begin() + n + 1);
  auto from1 = a[1].id;
  auto cost1 = a[1].cost;
  for (int i = 2; i <= n; ++i) e.push_back({from1, a[i].id, cost1 + a[i].cost});
  sort(e.begin(), e.end());
  cout << Kruskal() << '\n';
  return 0;
}
