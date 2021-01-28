#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;

class Node {
 public:
  friend class Matrix;

  explicit Node(int val = 0, Node* right = nullptr, Node* down = nullptr)
      : val_(val), right_(right), down_(down) {}
  ~Node() {}

 protected:
  int val_;
  Node *right_, *down_;
};

class Matrix {
 public:
  Matrix(int row_size, int col_size, int val = 0)
      : data_(row_size + 2, vector<Node*>(col_size + 2, nullptr)),
        row_size_(row_size),
        col_size_(col_size) {
    for (auto&& row : data_)
      for (auto&& i : row) i = new Node;
  }
  ~Matrix() {
    for (auto&& row : data_)
      for (auto&& i : row) delete i;
  }

  void Init() {
    for (int j = 0; j <= col_size_; ++j) {
      data_[0][j]->right_ = data_[0][j + 1];
      data_[0][j]->down_ = data_[1][j];
    }
    for (int i = 1; i <= row_size_; ++i) {
      data_[i][0]->right_ = data_[i][1];
      data_[i][0]->down_ = data_[i + 1][0];
    }
    for (int i = 1; i <= row_size_; ++i) {
      for (int j = 1; j <= col_size_; ++j) {
        int val;
        cin >> val;
        data_[i][j]->val_ = val;
        data_[i][j]->right_ = data_[i][j + 1];
        data_[i][j]->down_ = data_[i + 1][j];
      }
    }
  }

  void Print() {
    auto row_begin = data_[0][0];
    for (int i = 1; i <= row_size_; ++i) {
      if (!row_begin->down_) break;  // this statement shouldn't be run
      row_begin = row_begin->down_;
      auto cur = row_begin;
      for (int j = 1; j <= col_size_; ++j) {
        if (!cur->right_) break;  // this statement shouldn't be run
        cur = cur->right_;
        cout << cur->val_ << (j == col_size_ ? '\n' : ' ');
      }
    }
  }

  void Swap(int row1, int col1, int row2, int col2, int height, int width) {
    auto cur1 = data_[0][0];
    auto cur2 = data_[0][0];

    // Move cur1 to data_[row1][col1]
    for (int i = 0; i < row1; ++i) cur1 = cur1->down_;
    for (int j = 0; j < col1; ++j) cur1 = cur1->right_;
    // Move cur2 to data_[row2][col2]
    for (int i = 0; i < row2; ++i) cur2 = cur2->down_;
    for (int j = 0; j < col2; ++j) cur2 = cur2->right_;

    auto cur1_bak = cur1;
    auto cur2_bak = cur2;

    // Swap the first row
    swap(cur1->val_, cur2->val_);
    for (int j = 1; j < width; ++j) {
      cur1 = cur1->right_;
      cur2 = cur2->right_;
      swap(cur1->val_, cur2->val_);
      if (height > 1) swap(cur1->down_, cur2->down_);
    }
    // Swap the last column
    if (width > 1) {
      for (int i = 1; i < height; ++i) {
        cur1 = cur1->down_;
        cur2 = cur2->down_;
        swap(cur1->right_, cur2->right_);
      }
    }

    // Return cur1 and cur2 to initial position
    cur1 = cur1_bak;
    cur2 = cur2_bak;

    // Swap the first column
    for (int i = 1; i < height; ++i) {
      cur1 = cur1->down_;
      cur2 = cur2->down_;
      swap(cur1->val_, cur2->val_);
      if (width > 1) swap(cur1->right_, cur2->right_);
    }
    // Swap the last row
    if (height > 1) {
      for (int j = 1; j < width; ++j) {
        cur1 = cur1->right_;
        cur2 = cur2->right_;
        swap(cur1->down_, cur2->down_);
      }
    }
  }

 protected:
  vector<vector<Node*>> data_;
  int row_size_;
  int col_size_;
};

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  Matrix matrix(n, m);
  matrix.Init();
  for (int i = 0; i < q; ++i) {
    int a, b, c, d, h, w;
    cin >> a >> b >> c >> d >> h >> w;
    matrix.Swap(a, b, c, d, h, w);
    // cout << "Case " << i + 1 << ":\n";
    // matrix.Print();
    // cout << "\n";
  }
  matrix.Print();
  return 0;
}
