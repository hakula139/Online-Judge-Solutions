#include <cstdint>
#include <deque>
#include <iostream>

static std::deque<int> first_half;
static int             num = 0;

void Construct(int64_t count) {
    if (!count) return;
    if (count & 1) {
        Construct((count - 1) >> 1);
        first_half.push_back(++num);
    } else {
        Construct(count - 1);
        first_half.push_front(++num);
    }
}

int main() {
    int64_t n;
    std::cin >> n;
    Construct(n);
    std::cout << (num << 1) << '\n';
    while (!first_half.empty()) {
        std::cout << first_half.front() << ' ';
        first_half.pop_front();
    }
    for (int i = 1; i < num; ++i) std::cout << i << ' ';
    std::cout << num << '\n';
    return 0;
}
