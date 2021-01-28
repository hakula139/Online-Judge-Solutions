#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class HashTable {
 public:
  explicit HashTable(int size)
      : size_(size),
        hash1_(size + 1),
        hash2_(size + 1),
        seed1_(size + 1),
        seed2_(size + 1) {}

  bool Init(const string& str) {
    if (str.size() != size_) return false;
    seed1_[0] = seed2_[0] = 1;
    for (int i = 1; i <= size_; ++i) {
      hash1_[i] = (hash1_[i - 1] * kSeed_ + str[i - 1] - '0') % kMod1_;
      hash2_[i] = (hash2_[i - 1] * kSeed_ + str[i - 1] - '0') % kMod2_;
      seed1_[i] = seed1_[i - 1] * kSeed_ % kMod1_;
      seed2_[i] = seed2_[i - 1] * kSeed_ % kMod2_;
    }
    // cout << "Hash table 1: ";
    // for (const auto& i : hash1_) cout << i << ' ';
    // cout << '\n';
    // cout << "Hash table 2: ";
    // for (const auto& i : hash2_) cout << i << ' ';
    // cout << '\n';
    return true;
  }

  int64_t Hash1(const string& str, int begin, int end) {
    if (str.size() != size_) return -1;
    if (begin < 0 || end >= size_ || begin > end) return 0;
    int64_t hash1_end = hash1_[end + 1];
    int64_t hash1_begin = hash1_[begin];
    hash1_begin *= seed1_[end - begin + 1];
    int64_t hash1 = (hash1_end - hash1_begin % kMod1_ + kMod1_) % kMod1_;
    return hash1;
  }

  int64_t Hash2(const string& str, int begin, int end) {
    if (str.size() != size_) return -1;
    if (begin < 0 || end >= size_ || begin > end) return 0;
    int64_t hash2_end = hash2_[end + 1];
    int64_t hash2_begin = hash2_[begin];
    hash2_begin *= seed2_[end - begin + 1];
    int64_t hash2 = (hash2_end - hash2_begin % kMod2_ + kMod2_) % kMod2_;
    return hash2;
  }

  bool Validate1(int64_t hash1_a, int64_t hash1_b, int64_t hash1_c) {
    return !((hash1_a + hash1_b - hash1_c) % kMod1_);
  }

  bool Validate2(int64_t hash2_a, int64_t hash2_b, int64_t hash2_c) {
    return !((hash2_a + hash2_b - hash2_c) % kMod2_);
  }

 protected:
  const int64_t kSeed_ = 10;
  const int64_t kMod1_ = 1e9 + 233;
  const int64_t kMod2_ = 1e9 + 2019;
  int size_;
  vector<int64_t> hash1_;
  vector<int64_t> hash2_;
  vector<int64_t> seed1_;
  vector<int64_t> seed2_;
};

bool Print(const string& str, int begin_a, int begin_b, int begin_c) {
  int len = str.size();
  if (begin_a >= begin_b || begin_b >= begin_c) return false;
  if (begin_a < 0 || begin_c >= len) return false;
  for (int i = begin_a; i < begin_b; ++i) cout << str[i];
  cout << '+';
  for (int i = begin_b; i < begin_c; ++i) cout << str[i];
  cout << '=';
  for (int i = begin_c; i < len; ++i) cout << str[i];
  cout << '\n';
  return true;
}

int main() {
  string input;
  cin >> input;
  int len = input.size();

  HashTable hash(len);
  hash.Init(input);

  bool found = false;
  for (int i = len >> 1; i < len; ++i) {
    int len_c = len - i;
    for (int len_a : {len_c, len_c - 1, i - len_c, i - len_c + 1}) {
      int len_b = i - len_a;
      if (len_a < 1 || len_b < 1) continue;
      if (input[len_a] == '0' && len_b > 1) continue;

      // cout << "\nBefore hash: ";
      // Print(input, 0, len_a, i);

      int64_t a1 = hash.Hash1(input, 0, len_a - 1);
      int64_t b1 = hash.Hash1(input, len_a, i - 1);
      int64_t c1 = hash.Hash1(input, i, len - 1);
      // cout << "After hash1: ";
      // cout << a1 << '+' << b1 << '=' << c1 << '\n';
      if (!hash.Validate1(a1, b1, c1)) continue;

      int64_t a2 = hash.Hash2(input, 0, len_a - 1);
      int64_t b2 = hash.Hash2(input, len_a, i - 1);
      int64_t c2 = hash.Hash2(input, i, len - 1);
      // cout << "After hash2: ";
      // cout << a2 << '+' << b2 << '=' << c2 << '\n';
      if (!hash.Validate2(a2, b2, c2)) continue;

      // cout << "\nOutput: ";
      Print(input, 0, len_a, i);
      found = true;
      break;
    }
    if (found) break;
  }

  return 0;
}
