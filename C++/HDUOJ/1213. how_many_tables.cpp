#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

const int   kMaxSize = 1010;
vector<int> root(kMaxSize);
vector<int> rank(kMaxSize);

void MakeSet(int n) {
    for (int i = 1; i <= n; ++i) {
        root[i] = i;
        rank[i] = 0;
    }
}

int Find(int x) {
    if (root[x] == x) return x;
    return root[x] = Find(root[x]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (rank[a] < rank[b])
        root[a] = b;
    else if (rank[a] > rank[b])
        root[b] = a;
    else
        root[b] = a, ++rank[b];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        MakeSet(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }
        int result = 0;
        for (int i = 1; i <= n; ++i)
            if (root[i] == i) ++result;
        cout << result << '\n';
    }
    return 0;
}
