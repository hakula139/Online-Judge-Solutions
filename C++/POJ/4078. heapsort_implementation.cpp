#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// Min Heap by default
template <class T, template <class> class Cmp = std::less>
class Heap {
public:
    Heap() {}
    explicit Heap(size_t size) { data_.reserve(size); }

    void push(const T& val) {
        data_.push_back(val);
        AdjustUp(data_.size() - 1);
    }

    void pop() {
        if (empty()) {
            std::cerr << "Heap is empty.\n";
            return;
        }
        size_t size = data_.size();
        std::swap(data_[0], data_[size - 1]);
        data_.pop_back();
        AdjustDown(0);
    }

    T top() {
        if (empty()) {
            std::cerr << "Heap is empty.\n";
            return T();
        }
        return data_.front();
    }

    bool empty() { return data_.empty(); }

    void clear() { data_.clear(); }

protected:
    // Adjust from root to leaf
    void AdjustDown(size_t parent) {
        size_t child = (parent << 1) + 1;
        size_t size  = data_.size();
        while (child < size) {
            if (child + 1 < size && Compare(data_[child + 1], data_[child]))
                ++child;
            if (!Compare(data_[child], data_[parent])) break;
            std::swap(data_[child], data_[parent]);
            parent = child;
            child  = (child << 1) + 1;
        }
    }

    // Adjust from leaf to root
    void AdjustUp(size_t child) {
        size_t parent = (child - 1) >> 1;
        while (child > 0) {
            if (!Compare(data_[child], data_[parent])) break;
            std::swap(data_[child], data_[parent]);
            child  = parent;
            parent = (child - 1) >> 1;
        }
    }

    Cmp<T>         Compare;
    std::vector<T> data_;
};

int main() {
    size_t n;
    std::cin >> n;
    size_t    type = 0;
    int       val;
    Heap<int> heap(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> type;
        switch (type) {
            case 1:
                std::cin >> val;
                heap.push(val);
                break;
            case 2:
                std::cout << heap.top() << '\n';
                heap.pop();
                break;
            default: std::cerr << "Invalid operation.\n"; break;
        }
    }
    return 0;
}
