#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

using It = std::string::iterator;

bool Compare(It str1_begin, It str1_end, It str2_begin, It str2_end) {
    int len = str1_end - str1_begin;
    if (len <= 0) return true;
    if (len % 2) {
        while (len--)
            if (*(str1_begin++) != *(str2_begin++)) return false;
        return true;
    }
    It str1_mid = str1_begin + (len >> 1);
    It str2_mid = str2_begin + (len >> 1);
    if (Compare(str1_begin, str1_mid, str2_begin, str2_mid) &&
        Compare(str1_mid, str1_end, str2_mid, str2_end))
        return true;
    if (Compare(str1_begin, str1_mid, str2_mid, str2_end) &&
        Compare(str1_mid, str1_end, str2_begin, str2_mid))
        return true;
    return false;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    bool is_equal = Compare(str1.begin(), str1.end(), str2.begin(), str2.end());
    cout << (is_equal ? "YES\n" : "NO\n");
    return 0;
}
