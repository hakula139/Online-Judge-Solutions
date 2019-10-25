#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::queue;
using std::set;
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    set<int>            unread;
    int                 first_unread = 0;
    queue<int>          timeline;
    vector<vector<int>> apps(n + 1);
    for (int time = 0; time < q; ++time) {
        int op_type, op_arg;
        cin >> op_type >> op_arg;
        switch (op_type) {
            case 1:
                timeline.push(time);
                unread.insert(time);
                apps[op_arg].push_back(time);
                break;
            case 2:
                for (const auto& event : apps[op_arg]) unread.erase(event);
                apps[op_arg].clear();
                break;
            case 3:
                for (int i = 0; i < op_arg - first_unread; ++i) {
                    unread.erase(timeline.front());
                    timeline.pop();
                }
                first_unread = max(first_unread, op_arg);
                break;
            default: break;
        }
        cout << unread.size() << '\n';
    }
    return 0;
}
