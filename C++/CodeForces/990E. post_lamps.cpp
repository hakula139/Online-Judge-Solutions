#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

void Solution() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> block(n);
    for (int i = 0; i < m; ++i) {
        int pos;
        std::cin >> pos;
        if (!pos) {
            std::cout << -1 << '\n';
            return;
        }
        ++block[pos];
    }
    int len = 0;
    for (int i = 1; i < n; ++i) {
        if (block[i]) block[i] = block[i - 1] + 1;
        len = std::max(len, block[i]);
    }
    if (len >= k) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<int64_t> price(k);
    for (int i = 0; i < k; ++i) std::cin >> price[i];
    int64_t result = static_cast<int64_t>(1e12);
    for (len = len + 1; len <= k; ++len) {
        int64_t cnt = 0;
        for (int i = 0; i < n; i += len, ++cnt) {
            if (block[i]) i -= block[i];
        }
        result = std::min(result, cnt * price[len - 1]);
    }
    std::cout << result << '\n';
    return;
}

int main() {
    Solution();
    return 0;
}
