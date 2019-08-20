#include <iostream>
#include <string>

class Solution {
public:
    void Set(const std::string& preord, const std::string& inord) {
        preord_ = std::move(preord);
        inord_  = std::move(inord);
    }

    void Print(size_t preord_start_pos, size_t inord_start_pos, size_t size) {
        if (!size) return;

        auto root_ = preord_.at(preord_start_pos);
        if (size == 1) {
            std::cout << root_;
            return;
        }

        size_t root_pos_ = inord_.find(root_);

        size_t preord_left_start_pos_ = preord_start_pos + 1;
        size_t inord_left_start_pos_  = inord_start_pos;
        size_t left_size_             = root_pos_ - inord_start_pos;
        Print(preord_left_start_pos_, inord_left_start_pos_, left_size_);

        size_t preord_right_start_pos_ = preord_start_pos + left_size_ + 1;
        size_t inord_right_start_pos_  = root_pos_ + 1;
        size_t right_size_             = size - left_size_ - 1;
        Print(preord_right_start_pos_, inord_right_start_pos_, right_size_);

        std::cout << root_;
    }

private:
    std::string preord_;
    std::string inord_;
};

int main() {
    Solution    ans;
    std::string preord, inord;
    while (std::cin >> preord >> inord) {
        ans.Set(preord, inord);
        ans.Print(0, 0, preord.size());
        std::cout << '\n';
    }
    return 0;
}
