#include <deque>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::deque;
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    while (cin >> n) {
        if (!n) break;
        int         size = n << 1;
        vector<int> seq(size);
        for (int i = 0; i < n; ++i) {
            cin >> seq[i];
            seq[i + n] = seq[i];
        }
        vector<int> sum(size + 1);
        for (int i = 1; i <= size; ++i) sum[i] = sum[i - 1] + seq[i - 1];

        int        count = 0;
        deque<int> index;
        for (int i = 1; i <= n; ++i) {
            while (!index.empty() && sum[i] <= sum[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        for (int i = n; i < size; ++i) {
            while (!index.empty() && i - index.front() >= n) index.pop_front();
            while (!index.empty() && sum[i] <= sum[index.back()])
                index.pop_back();
            index.push_back(i);
            if (sum[index.front()] >= sum[i - n]) ++count;
        }
        cout << count << '\n';
    }
    return 0;
}
