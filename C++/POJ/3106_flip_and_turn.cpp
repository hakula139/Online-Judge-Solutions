#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

template <class T>
class Matrix {
 public:
  Matrix(size_t row_size, size_t col_size)
      : row_size_(row_size), col_size_(col_size) {
    InitMatrix(&matrix_, row_size_, col_size_);
    InitDict();
  }

  void SetMatrix() {
    for (size_t i = 0; i < row_size_; ++i) {
      for (size_t j = 0; j < col_size_;) {
        T val;
        std::cin >> val;
        std::cin.clear();
        matrix_[i][j++] = val;
      }
    }
  }

  void SetOperations() {
    char op;
    while (std::cin.get(op)) {
      if (op == '\n') continue;
      std::string real_op = dict_.at(op);
      size_t len = real_op.size();
      if (ops.empty()) {
        ops += real_op;
        continue;
      }
      for (size_t i = 0; i < len; ++i) {
        size_t ops_len = ops.size();
        // if (real_op[i] == ops.back()) {
        if (real_op[i] == ops[ops_len - 1]) {
          // Repeat the same operation twice does nothing.
          // ops.pop_back();
          ops.erase(ops_len - 1, 1);
          continue;
        } else {
          ops += real_op[i];
          if (ops.size() >= 8) {
            // Operation "01010101" and "10101010"
            // will both restore the matrix.
            ops.erase(0, 8);
          }
        }
      }
    }
  }

  // Transposition by the main diagonal (Operation "0")
  void Transpose() {
    std::vector<std::vector<T>> new_matrix;
    InitMatrix(&new_matrix, col_size_, row_size_);
    for (size_t i = 0; i < col_size_; ++i)
      for (size_t j = 0; j < row_size_; ++j) new_matrix[i][j] = matrix_[j][i];
    matrix_ = new_matrix;
    std::swap(row_size_, col_size_);
  }

  // Vertical flip (Operation "1")
  void Flip() {
    for (size_t i = 0; i < row_size_; ++i)
      std::reverse(matrix_[i].begin(), matrix_[i].end());
  }

  void Operate() {
    size_t len = ops.size();
    for (size_t i = 0; i < len; ++i) {
      ops[i] == '0' ? Transpose() : Flip();
    }
  }

  void Output() {
    // std::cout << ops << "#\n";  // DEBUG
    std::cout << row_size_ << ' ' << col_size_ << '\n';
    for (size_t i = 0; i < row_size_; ++i) {
      for (size_t j = 0; j < col_size_; ++j) std::cout << matrix_[i][j];
      std::cout << '\n';
    }
  }

 protected:
  void InitMatrix(std::vector<std::vector<T>>* p_matrix, size_t row_size,
                  size_t col_size) {
    p_matrix->clear();
    p_matrix->reserve(row_size);
    for (size_t i = 0; i < row_size; ++i)
      p_matrix->push_back(std::vector<T>(col_size, 0));
  }

  // "0" for 'Transposition by the main diagonal';
  // "1" for 'Vertical flip'.
  void InitDict() {
    dict_.clear();
    dict_.insert(std::pair<char, std::string>('1', "0"));
    dict_.insert(std::pair<char, std::string>('2', "101"));
    dict_.insert(std::pair<char, std::string>('H', "010"));
    dict_.insert(std::pair<char, std::string>('V', "1"));
    dict_.insert(std::pair<char, std::string>('A', "01"));
    dict_.insert(std::pair<char, std::string>('Z', "01"));
    dict_.insert(std::pair<char, std::string>('B', "0101"));
    dict_.insert(std::pair<char, std::string>('Y', "0101"));
    dict_.insert(std::pair<char, std::string>('C', "10"));
    dict_.insert(std::pair<char, std::string>('X', "10"));
  }

  std::vector<std::vector<T>> matrix_;
  std::map<char, std::string> dict_;
  size_t row_size_;
  size_t col_size_;
  std::string ops;
};

int main() {
  size_t row_size, col_size;
  std::cin >> row_size >> col_size;
  Matrix<char> data(row_size, col_size);
  data.SetMatrix();
  data.SetOperations();
  data.Operate();
  data.Output();
  return 0;
}
