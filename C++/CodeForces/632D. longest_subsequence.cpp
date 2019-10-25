#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int>   arr(n);
    map<int, int> num_cnt;
    vector<int>   all_cnt(m + 1);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr[i] = num;
        ++num_cnt[num];
    }
    for (const auto& i : num_cnt) {
        int num = i.first;
        int cnt = i.second;
        for (int j = num; j <= m; j += num) all_cnt[j] += cnt;
    }

    int max = 0;
    int lcm = 1;
    for (int i = 1; i <= m; ++i) {
        if (all_cnt[i] > max) {
            max = all_cnt[i];
            lcm = i;
        }
    }
    vector<int> subseq;
    for (int i = 0; i < n; ++i) {
        if (!max) break;
        if (!(lcm % arr[i])) subseq.push_back(i + 1);
    }

    cout << lcm << ' ' << subseq.size() << '\n';
    bool first_output = true;
    for (const auto& i : subseq) {
        if (first_output)
            first_output = false;
        else
            cout << ' ';
        cout << i;
    }
    cout << '\n';
    return 0;
}
