#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> GetNext(const vector<int>& arr) {
    int         size = arr.size();
    vector<int> next_arr(size + 1);
    int         i = 0, j = -1;
    next_arr[0] = -1;
    while (i < size) {
        if (j == -1 || arr[i] == arr[j]) {
            ++i, ++j;
            next_arr[i] = (arr[i] != arr[j] ? j : next_arr[j]);
        } else {
            j = next_arr[j];
        }
    }
    return next_arr;
}

int KmpSearch(const vector<int>& arr_a,
              const vector<int>& arr_b,
              const vector<int>& next_arr,
              int                start_pos,
              int                step) {
    int size_a = arr_a.size() - 1;
    int size_b = arr_b.size() - 1;
    int i      = start_pos;
    int j      = 0;
    int sum    = 0;
    while (i < size_a) {
        if (j == -1 || arr_a[i] == arr_b[j])
            i += step, ++j;
        else
            j = next_arr[j];
        if (j == size_b) ++sum, j = next_arr[j];
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int case_i = 1; case_i <= t; ++case_i) {
        int n, m, p;
        cin >> n >> m >> p;
        vector<int> arr_a(n + 1);
        vector<int> arr_b(m + 1);
        for (int i = 0; i < n; ++i) cin >> arr_a[i];
        for (int i = 0; i < m; ++i) cin >> arr_b[i];

        int         sum      = 0;
        vector<int> next_arr = GetNext(arr_b);
        for (int i = 0; i < p; ++i) {
            if (i + p * (m - 1) >= n) break;
            sum += KmpSearch(arr_a, arr_b, next_arr, i, p);
        }
        cout << "Case #" << case_i << ": " << sum << '\n';
    }
    return 0;
}
