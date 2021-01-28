#include <iostream>
#include <string>
#include <vector>

class SpellChecker {
 public:
  void AddWordToDict(const std::string& word) {
    dict_.push_back(std::make_pair(word, word.length()));
  }

  void PrintAllReplacements() {
    for (auto&& i : replacements_) std::cout << ' ' << i;
  }

  bool IsCorrect(const std::string& word) {
    replacements_.clear();
    size_t word_len_ = word.length();
    for (auto i = dict_.begin(); i != dict_.end(); ++i) {
      size_t target_len_ = i->second;
      if (word_len_ == target_len_) {
        bool flag_ = IsCorrect(word, i->first);
        if (flag_) return true;
        CorrectByReplacing(word, i->first);
      }
      if (word_len_ + 1 == target_len_) {
        CorrectByInserting(word, i->first);
      }
      if (word_len_ - 1 == target_len_) {
        CorrectByDeleting(word, i->first);
      }
    }
    return false;
  }

  bool IsCorrect(const std::string& word, const std::string& target) {
    return word == target;
  }

  bool CorrectByReplacing(const std::string& word, const std::string& target) {
    size_t diff_count = 0;
    auto i1 = word.begin();
    auto i2 = target.begin();
    for (; i1 < word.end(); ++i1, ++i2) {
      if (*i1 == *i2) continue;
      if (++diff_count > 1) return false;
    }
    replacements_.push_back(target);
    return true;
  }

  bool CorrectByInserting(const std::string& word, const std::string& target) {
    size_t diff_count = 0;
    auto i1 = word.begin();
    auto i2 = target.begin();
    for (; i1 < word.end(); ++i2) {
      if (*i1 == *i2) {
        ++i1;
        continue;
      }
      if (++diff_count > 1) return false;
    }
    replacements_.push_back(target);
    return true;
  }

  bool CorrectByDeleting(const std::string& word, const std::string& target) {
    size_t diff_count = 0;
    auto i1 = word.begin();
    auto i2 = target.begin();
    for (; i1 < word.end(); ++i1) {
      if (*i1 == *i2) {
        ++i2;
        continue;
      }
      if (++diff_count > 1) return false;
    }
    replacements_.push_back(target);
    return true;
  }

 private:
  std::vector<std::pair<std::string, size_t>> dict_;
  std::vector<std::string> replacements_;
};

int main() {
  SpellChecker checker;
  std::string input;
  while (std::cin >> input) {
    if (input == "#") break;
    checker.AddWordToDict(input);
  }
  while (std::cin >> input) {
    if (input == "#") break;
    bool result_flag = checker.IsCorrect(input);
    std::cout << input;
    if (result_flag) {
      std::cout << " is correct\n";
    } else {
      std::cout << ':';
      checker.PrintAllReplacements();
      std::cout << '\n';
    }
  }
  return 0;
}
