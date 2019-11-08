#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::greater;
using std::priority_queue;
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int sub       = 0;
    using MinHeap = priority_queue<int, vector<int>, greater<int>>;
    MinHeap heap;
    while (n--) {
        int num;
        cin >> num;
        heap.push(num);
    }
    while (k--) {
        while (!heap.empty() && heap.top() == sub) heap.pop();
        if (heap.empty()) {
            cout << 0 << '\n';
            continue;
        }
        int num = heap.top();
        cout << num - sub << '\n';
        sub = num;
        heap.pop();
    }
    return 0;
}
