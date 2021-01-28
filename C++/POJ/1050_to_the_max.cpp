#include <iostream>
#include <vector>

class Matrix {
 public:
  Matrix(size_t row_size, size_t col_size)
      : row_size_(row_size), col_size_(col_size) {
    matrix_.reserve(row_size);
    for (size_t i = 0; i < row_size; ++i)
      matrix_.push_back(std::vector<int>(col_size, 0));
  }

  void Init() {
    for (size_t i = 0; i < row_size_; ++i)
      for (size_t j = 0; j < col_size_; ++j) std::cin >> matrix_[i][j];
  }

  int MaxMatrixSum() {
    int max = matrix_[0][0];
    int row_max;
    std::vector<int> sum_array(col_size_, 0);  // Compress matrix to vector
    for (size_t start_row = 0; start_row < row_size_; ++start_row) {
      for (size_t i = 0; i < col_size_; ++i) sum_array[i] = 0;
      for (size_t row = start_row; row < row_size_; ++row) {
        for (size_t col = 0; col < col_size_; ++col) {
          sum_array[col] += matrix_[row][col];
        }
        row_max = MaxArraySum(sum_array);
        max = row_max > max ? row_max : max;
      }
    }
    return max;
  }

  int MaxArraySum(const std::vector<int>& array) {
    int max = array[0];
    int sum = 0;
    size_t size = array.size();
    for (size_t i = 0; i < size; ++i) {
      sum = array[i] + (sum > 0 ? sum : 0);
      max = sum > max ? sum : max;
    }
    return max;
  }

 protected:
  std::vector<std::vector<int>> matrix_;
  size_t row_size_;
  size_t col_size_;
};

int main() {
  size_t n;
  std::cin >> n;
  Matrix data(n, n);
  data.Init();
  std::cout << data.MaxMatrixSum() << '\n';
  return 0;
}
