#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> queue(n);
    for (int i = 0; i < n; ++i) std::cin >> queue[i];
    std::sort(queue.begin(), queue.end());
    int total_time = 0;
    int cnt        = 1;
    for (int i = 1; i < n; ++i) {
        total_time += queue[i - 1];
        while (i < n && total_time > queue[i]) ++i;
        if (i < n) ++cnt;
    }
    std::cout << cnt << '\n';
    return 0;
}
