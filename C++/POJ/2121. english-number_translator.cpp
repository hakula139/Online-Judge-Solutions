#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Translator {
public:
    static std::map<std::string, int> dict_;

    int Translate(const std::string& english) {
        std::vector<int>   numbers_;
        std::istringstream english_(english);
        std::string        word_;

        bool is_positive = true;
        int  number_     = 0;
        while (english_ >> word_) {
            switch (dict_[word_]) {
                case -1: is_positive = false; break;
                case 100: number_ *= 100; break;
                case -3:  // thousand
                    numbers_.push_back(number_);
                    numbers_.push_back(-3);  // thousand flag
                    number_ = 0;
                    break;
                case -6:  // million
                    numbers_.push_back(number_);
                    numbers_.push_back(-6);  // million flag
                    number_ = 0;
                    break;
                default: number_ += dict_[word_]; break;
            }
        }
        if (number_) numbers_.push_back(number_);

        int result_ = 0;
        int tmp_    = 0;
        for (auto&& i : numbers_) {
            switch (i) {
                case -3: tmp_ *= 1000; break;
                case -6:
                    result_ += tmp_ * 1000000;
                    tmp_ = 0;
                    break;
                default: tmp_ += i; break;
            }
        }
        if (tmp_) result_ += tmp_;

        return is_positive ? result_ : -result_;
    }
};

std::map<std::string, int> Translator::dict_{
    {"negative", -1}, {"zero", 0},      {"one", 1},        {"two", 2},
    {"three", 3},     {"four", 4},      {"five", 5},       {"six", 6},
    {"seven", 7},     {"eight", 8},     {"nine", 9},       {"ten", 10},
    {"eleven", 11},   {"twelve", 12},   {"thirteen", 13},  {"fourteen", 14},
    {"fifteen", 15},  {"sixteen", 16},  {"seventeen", 17}, {"eighteen", 18},
    {"nineteen", 19}, {"twenty", 20},   {"thirty", 30},    {"forty", 40},
    {"fifty", 50},    {"sixty", 60},    {"seventy", 70},   {"eighty", 80},
    {"ninety", 90},   {"hundred", 100}, {"thousand", -3},  {"million", -6}};

int main() {
    Translator  translator;
    std::string english;
    int         number;
    while (!std::cin.eof()) {
        std::getline(std::cin, english);
        if (english.empty()) break;
        number = translator.Translate(english);
        std::cout << number << '\n';
    }
    return 0;
}
