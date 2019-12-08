#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int case_i = 1; case_i <= t; ++case_i) {
        int n, k;
        cin >> n >> k;
        unordered_map<uint64_t, bool> sum_map;
        sum_map[0]     = 0;
        uint64_t sum   = 0;
        bool     found = false;
        for (int i = 1; i <= n; ++i) {
            uint64_t num;
            cin >> num;
            if (found) continue;
            bool is_odd = i & 1;
            sum += is_odd ? num : -num;
            auto pos = sum_map.find(sum + k);
            if (pos != sum_map.end() && pos->second) found = true;
            pos = sum_map.find(sum - k);
            if (pos != sum_map.end() && !pos->second) found = true;
            sum_map[sum] = is_odd;
        }
        cout << "Case #" << case_i << ": " << (found ? "Yes.\n" : "No.\n");
    }
    return 0;
}
