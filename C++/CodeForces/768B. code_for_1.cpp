#include <cstdint>
#include <iostream>

int64_t Size(int64_t num) {
    if (num <= 1) return 1;
    return (Size(num >> 1) << 1) + 1;
}

int64_t
Count(int64_t num, int64_t left, int64_t right, int64_t start, int64_t end) {
    if (start > end || left > right) return 0;
    if (num <= 1) return num;
    int64_t mid = left + ((right - left) >> 1);
    if (end < mid) {
        return Count(num >> 1, left, mid - 1, start, end);
    } else if (start > mid) {
        return Count(num >> 1, mid + 1, right, start, end);
    } else {
        int64_t left_count  = Count(num >> 1, left, mid - 1, start, mid - 1);
        int64_t right_count = Count(num >> 1, mid + 1, right, mid + 1, end);
        return left_count + right_count + (num & 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t n, l, r;
    std::cin >> n >> l >> r;
    std::cout << Count(n, 1, Size(n), l, r) << '\n';
    return 0;
}
