#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int k = 9973;
    int       t;
    std::cin >> t;
    while (t--) {
        int n, b;
        std::cin >> n >> b;
        b %= k, n = n % k - k;
        int y = 1;
        for (int x = 0; x < k; ++x) {
            y = (b * x - n) % k;
            if (!y) std::cout << x << '\n';
        }
    }
    return 0;
}
