#include <algorithm>
#include <iostream>
#include <vector>

struct Square {
    Square() : size_(0), left_(0), right_(0) {}
    explicit Square(size_t size) : size_(size), left_(0), right_(size << 1) {}
    size_t size_;
    int    left_, right_;  // after multiplying sqrt(2)
};

int main() {
    size_t n;
    while (std::cin >> n) {
        if (!n) break;
        size_t              size;
        std::vector<Square> sqrs;
        for (size_t i = 0; i < n; ++i) {
            std::cin >> size;
            sqrs.push_back(Square(size));
            for (size_t j = 0; j < i; ++j) {
                int left = sqrs[j].size_ > size ?
                               sqrs[j].left_ + sqrs[j].size_ + size :
                               sqrs[j].left_ + sqrs[j].size_ * 3 - size;
                sqrs.back().left_ = std::max(sqrs.back().left_, left);
            }
            sqrs.back().right_ = sqrs.back().left_ + (sqrs.back().size_ << 1);
        }
        bool first_output = true;
        for (size_t i = 0; i < n; ++i) {
            int    left = 0, right = sqrs.back().right_;
            size_t j;
            for (j = 0; j < i; ++j) {
                if (sqrs[j].size_ > sqrs[i].size_)
                    left = std::max(left, sqrs[j].right_);
                if (left >= sqrs[i].right_) break;
            }
            if (j < i) continue;
            for (j = i + 1; j < n; ++j) {
                if (sqrs[j].size_ > sqrs[i].size_)
                    right = std::min(right, sqrs[j].left_);
                if (right <= sqrs[i].left_) break;
            }
            if (j < n) continue;
            if (left < right) {
                if (first_output)
                    first_output = false;
                else
                    std::cout << ' ';
                std::cout << i + 1;
            }
        }
        std::cout << '\n';
    }
    return 0;
}
