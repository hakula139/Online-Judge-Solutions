#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::map;
using std::max;
using std::string;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        map<string, int> balloons;
        int              max_count = 0;
        while (n--) {
            string color;
            cin >> color;
            ++balloons[color];
            max_count = max(max_count, balloons[color]);
        }
        for (const auto& i : balloons)
            if (i.second == max_count) cout << i.first << '\n';
    }
    return 0;
}
