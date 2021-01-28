#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int64_t kMaxSize = 1e6 + 233;

class HashTable {
 public:
  explicit HashTable(const string& str)
      : size_(str.size()), hash_(size_ + 1), seed_(size_ + 1) {
    seed_[0] = 1;
    for (int i = 1; i <= size_; ++i) {
      hash_[i] = (hash_[i - 1] * kSeed_ + str[i - 1] - 'A') % kMod_;
      seed_[i] = seed_[i - 1] * kSeed_ % kMod_;
    }
  }

  int64_t Hash(int begin, int end) {
    if (begin < 0 || end >= size_ || begin > end) return 0;
    int64_t hash_end = hash_[end + 1];
    int64_t hash_begin = hash_[begin];
    hash_begin *= seed_[end - begin + 1];
    int64_t hash = (hash_end - hash_begin % kMod_ + kMod_) % kMod_;
    return hash;
  }

  int64_t Seed(int index) { return seed_[index]; }

 protected:
  const int64_t kSeed_ = 8;
  const int64_t kMod_ = 1e6 + 233;
  int size_;
  vector<int64_t> hash_;
  vector<int64_t> seed_;
};

string Translate(int64_t hash, int len, int seed) {
  string str;
  while (len--) {
    char cur_char = hash % seed + 'A';
    str = cur_char + str;
    hash /= seed;
  }
  return str;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    string src;
    cin >> src;
    int src_len = src.size();
    HashTable hash_table(src);
    bool found = false;
    for (int len = 1; len < src_len; ++len) {
      vector<int64_t> all_cases(kMaxSize, true);
      for (int i = 0; i <= src_len - len; ++i) {
        int64_t hash = hash_table.Hash(i, i + len - 1);
        all_cases[hash] = false;
        // cout << "false: hash = " << hash << '\n';
      }
      int64_t end_pos = hash_table.Seed(len);
      for (int64_t i = 0; i < end_pos; ++i) {
        if (!all_cases[i]) continue;
        // cout << "true: hash = " << i << '\n';
        cout << Translate(i, len, hash_table.Seed(1)) << '\n';
        found = true;
        break;
      }
      if (found) break;
    }
  }
  return 0;
}
