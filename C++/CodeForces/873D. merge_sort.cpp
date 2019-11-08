#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;

class Solution {
public:
    explicit Solution(int n, int k) : permutation_(n), n_(n), k_(k) {
        if (k_ % 2) {
            for (int i = 0; i < n; ++i) permutation_[i] = i + 1;
        }
    }

    bool Solve() {
        if (!(k_ % 2)) return false;
        Solve(0, n_);
        return k_ == 1;
    }

    void PrintPermutation() {
        for (int i = 0; i < n_ - 1; ++i) cout << permutation_[i] << ' ';
        cout << permutation_.back() << '\n';
    }

protected:
    void Solve(int low, int high) {
        if (k_ == 1 || low >= high - 1) return;
        int mid = low + ((high - low) >> 1);
        swap(permutation_[mid - 1], permutation_[mid]);
        k_ -= 2;
        Solve(low, mid);
        Solve(mid, high);
    }

    vector<int> permutation_;
    int         n_;
    int         k_;
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    Solution s(n, k);
    if (s.Solve())
        s.PrintPermutation();
    else
        cout << -1 << '\n';
    return 0;
}
