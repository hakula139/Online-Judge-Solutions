#include <iostream>
#include <queue>

int main() {
    size_t n = 0;
    std::cin >> n;
    std::priority_queue<unsigned, std::vector<unsigned>, std::greater<unsigned>>
        queue;
    while (n--) {
        unsigned val = 0;
        std::cin >> val;
        queue.push(val);
    }
    size_t total_external_len = 0;
    while (queue.size() > 1) {
        unsigned left = queue.top();
        queue.pop();
        unsigned right = queue.top();
        queue.pop();
        size_t len = left + right;
        queue.push(len);
        total_external_len += len;
    }
    std::cout << total_external_len << '\n';
    return 0;
}
