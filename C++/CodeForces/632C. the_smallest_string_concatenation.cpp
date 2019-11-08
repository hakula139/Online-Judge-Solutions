#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::greater;
using std::priority_queue;
using std::string;
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    auto cmp = [](const string& str1, const string& str2) {
        return str1 + str2 > str2 + str1;
    };
    priority_queue<string, vector<string>, decltype(cmp)> strs(cmp);
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        strs.push(input);
    }
    while (n--) {
        cout << strs.top();
        strs.pop();
    }
    cout << '\n';
    return 0;
}
