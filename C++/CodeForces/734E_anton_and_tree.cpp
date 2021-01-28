#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

static constexpr int kMaxSize = 233333;
static vector<int> color(kMaxSize);
static vector<int> parent(kMaxSize);
static vector<vector<int>> edge(kMaxSize);
static vector<vector<int>> new_edge(kMaxSize);
static vector<int> visited(kMaxSize);
static vector<int> depth(kMaxSize);
static int cnt = 0;

void DFS1(int cur, int new_parent) {
  visited[cur] = 1;
  parent[cur] = new_parent;
  for (const auto& next : edge[cur]) {
    if (visited[next] || color[next] != color[cur]) continue;
    DFS1(next, new_parent);
  }
}

void DFS2(int cur, int parent, int* deepest_node) {
  depth[cur] = depth[parent] + 1;
  if (depth[cur] > depth[*deepest_node]) *deepest_node = cur;
  for (const auto& i : new_edge[cur]) {
    if (i == parent) continue;
    DFS2(i, cur, deepest_node);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> color[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) DFS1(i, ++cnt);
  }
  for (int i = 1; i <= n; ++i) {
    for (const auto& next : edge[i])
      if (color[next] != color[i]) new_edge[parent[i]].push_back(parent[next]);
  }
  for (int i = 1; i <= n; ++i) visited[i] = 0;

  // for (int i = 1; i <= n; ++i) {
  //     cout << i << ":\t";
  //     for (const auto& next : new_edge[i]) cout << ' ' << next;
  //     cout << '\n';
  // }

  int deepest_node = 1;
  DFS2(1, 1, &deepest_node);
  depth[deepest_node] = 0;
  DFS2(deepest_node, deepest_node, &deepest_node);
  cout << (depth[deepest_node] >> 1) << '\n';

  return 0;
}
