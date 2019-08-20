#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class BigNumber {
public:
    static const size_t kDigitThreshold_ = 10;

    BigNumber() : value_() {}
    explicit BigNumber(const std::string& value) : value_(value) {}
    BigNumber(const BigNumber& that) : value_(that.value_) {}
    BigNumber(BigNumber&& that) : value_(std::move(that.value_)) {}
    BigNumber& operator=(const BigNumber& that) {
        value_ = that.value_;
        return *this;
    }
    BigNumber& operator=(BigNumber&& that) {
        value_ = std::move(that.value_);
        return *this;
    }
    ~BigNumber() {}

    void        set_value() { value_.clear(); }
    void        set_value(const std::string& value) { value_ = value; }
    std::string value() const { return value_; }

    void AddZero(size_t zero_count, bool isPrefix = true) {
        if (!zero_count) return;
        isPrefix ? set_value(std::string(zero_count, '0') + value_) :
                   set_value(value_ + std::string(zero_count, '0'));
        // std::cout << "After AddZero(): " << value_ << "\n";
    }

    void RemoveZero() {
        auto start_pos = value_.find_first_not_of('0');
        start_pos == std::string::npos ? set_value("0") :
                                         set_value(value_.substr(start_pos));
        // std::cout << "After RemoveZero(): " << value_ << "\n";
    }

    bool IsZero() const { return !value_.length() || value_ == "0"; }

    friend BigNumber operator+(const BigNumber& num1, const BigNumber& num2);
    friend BigNumber operator-(const BigNumber& num1, const BigNumber& num2);
    friend BigNumber operator*(const BigNumber& num1, const BigNumber& num2);

    friend std::istream& operator>>(std::istream& input, BigNumber& num);
    friend std::ostream& operator<<(std::ostream& output, const BigNumber& num);

private:
    std::string value_;
};

BigNumber operator+(const BigNumber& num1, const BigNumber& num2) {
    if (num1.IsZero()) return num2;
    if (num2.IsZero()) return num1;

    size_t len1 = num1.value_.length();
    size_t len2 = num2.value_.length();

    size_t            max_len = std::max(len1, len2) + 1;
    std::vector<char> result_vec(max_len);

    BigNumber num1_ = num1;
    BigNumber num2_ = num2;
    len1 < len2 ? num1_.AddZero(len2 - len1) : num2_.AddZero(len1 - len2);

    {
        auto i  = ++result_vec.begin();
        auto i1 = num1_.value_.begin();
        auto i2 = num2_.value_.begin();
        for (; i != result_vec.end(); ++i, ++i1, ++i2) {
            *i = *i1 + *i2 - 2 * '0';
        }
    }

    for (auto i = result_vec.rbegin(); i != result_vec.rend(); ++i) {
        if (*i >= 10) {
            ++*(i + 1);
            *i -= 10;
        }
        *i += '0';
    }

    BigNumber result_num(std::string(result_vec.begin(), result_vec.end()));
    result_num.RemoveZero();
    // std::cout << "After constructor: " << result_num << "\n";
    return result_num;
}

BigNumber operator-(const BigNumber& num1, const BigNumber& num2) {
    if (num2.IsZero()) return num1;

    size_t len1 = num1.value_.length();
    size_t len2 = num2.value_.length();

    size_t            max_len = len1;
    std::vector<char> result_vec(max_len);

    BigNumber num2_ = num2;
    num2_.AddZero(len1 - len2);

    {
        auto i  = result_vec.begin();
        auto i1 = num1.value_.begin();
        auto i2 = num2_.value_.begin();
        for (; i != result_vec.end(); ++i, ++i1, ++i2) { *i = *i1 - *i2; }
    }

    for (auto i = result_vec.rbegin(); i != result_vec.rend(); ++i) {
        if (*i < 0) {
            --*(i + 1);
            *i += 10;
        }
        *i += '0';
    }

    BigNumber result_num(std::string(result_vec.begin(), result_vec.end()));
    result_num.RemoveZero();
    // std::cout << "After constructor: " << result_num << "\n";
    return result_num;
}

BigNumber operator*(const BigNumber& num1, const BigNumber& num2) {
    if (num1.IsZero() || num2.IsZero()) return BigNumber("0");

    size_t len1 = num1.value_.length();
    size_t len2 = num2.value_.length();

    if (len1 < BigNumber::kDigitThreshold_ &&
        len2 < BigNumber::kDigitThreshold_) {
        return BigNumber(
            std::to_string(std::stoll(num1.value_) * std::stoll(num2.value_)));
    }

    size_t half_len = std::min(std::max(len1, len2) >> 1, std::min(len1, len2));

    BigNumber num1_1(num1.value_.substr(0, len1 - half_len));
    BigNumber num1_0(num1.value_.substr(len1 - half_len));
    BigNumber num2_1(num2.value_.substr(0, len2 - half_len));
    BigNumber num2_0(num2.value_.substr(len2 - half_len));

    BigNumber result_2 = num1_1 * num2_1;
    BigNumber result_0 = num1_0 * num2_0;
    BigNumber result_1 =
        (num1_1 + num1_0) * (num2_1 + num2_0) - result_2 - result_0;

    if (result_2.value_ != "0") result_2.AddZero(half_len << 1, false);
    if (result_1.value_ != "0") result_1.AddZero(half_len, false);
    return result_2 + result_1 + result_0;
}

std::istream& operator>>(std::istream& input, BigNumber& num) {
    input >> num.value_;
    return input;
}

std::ostream& operator<<(std::ostream& output, const BigNumber& num) {
    output << num.value_;
    return output;
}

int main() {
    BigNumber num1, num2;
    std::cin >> num1 >> num2;
    std::cout << num1 * num2 << "\n";

    return 0;
}
