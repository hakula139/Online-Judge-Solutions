#include <algorithm>
#include <cstdio>
#include <deque>
#include <vector>

using std::deque;
using std::getchar;
using std::move_backward;
using std::vector;

void QuickRead(int* p_num) {
    *p_num     = 0;
    char digit = getchar();
    for (; digit < '0' || digit > '9'; digit = getchar()) {}
    for (; digit >= '0' && digit <= '9'; digit = getchar())
        *p_num = *p_num * 10 + digit - '0';
}

int main() {
    int n, q;
    while (scanf_s("%d%d", &n, &q) != EOF) {
        vector<deque<int>> lists(n + 1);
        int                op, u, v, w, val;
        while (q--) {
            QuickRead(&op);
            switch (op) {
                case 1:
                    QuickRead(&u);
                    QuickRead(&w);
                    QuickRead(&val);
                    if (w)
                        lists[u].push_back(val);
                    else
                        lists[u].push_front(val);
                    break;
                case 2:
                    QuickRead(&u);
                    QuickRead(&w);
                    if (lists[u].empty()) {
                        printf_s("-1\n");
                    } else if (w) {
                        printf_s("%d\n", lists[u].back());
                        lists[u].pop_back();
                    } else {
                        printf_s("%d\n", lists[u].front());
                        lists[u].pop_front();
                    }
                    break;
                case 3:
                    QuickRead(&u);
                    QuickRead(&v);
                    QuickRead(&w);
                    lists[u].resize(lists[u].size() + lists[v].size());
                    if (w)
                        move_backward(lists[v].rbegin(), lists[v].rend(),
                                      lists[u].end());
                    else
                        move_backward(lists[v].begin(), lists[v].end(),
                                      lists[u].end());
                    lists[v].clear();
                    break;
                default: break;
            }
        }
    }
    return 0;
}
