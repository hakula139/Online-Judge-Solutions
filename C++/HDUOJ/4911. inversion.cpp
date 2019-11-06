#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::move;
using std::vector;

static int64_t cnt = 0;

template <class It>
void Merge(It low, It mid, It high) {
    using T = typename std::iterator_traits<It>::value_type;
    vector<T> merged_arr(high - low);
    It        low_i  = low;
    It        high_i = mid;
    It        i      = merged_arr.begin();
    for (; low_i < mid && high_i < high; ++i) {
        if (*low_i <= *high_i) {
            *i = move(*(low_i++));
        } else {
            *i = move(*(high_i++));
            cnt += static_cast<int64_t>(mid - low_i);
        }
    }
    if (low_i < mid)
        move(low_i, mid, i);
    else
        move(high_i, high, i);
    move(merged_arr.begin(), merged_arr.end(), low);
}

template <class It>
void MergeSort(It low, It high) {
    if (low >= high - 1) return;
    It mid = low + ((high - low) >> 1);
    MergeSort(low, mid);
    MergeSort(mid, high);
    Merge(low, mid, high);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int     n;
    int64_t k;
    while (cin >> n >> k) {
        vector<int> nums(n);
        for (auto&& i : nums) cin >> i;
        cnt = 0;
        MergeSort(nums.begin(), nums.end());
        // for (const auto& i : nums) cout << i << ' ';
        // cout << '\n';
        cnt -= k;
        cout << std::max(cnt, 0ll) << '\n';
    }
    return 0;
}
