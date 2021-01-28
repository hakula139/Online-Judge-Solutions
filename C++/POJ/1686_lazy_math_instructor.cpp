#include <cctype>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <stack>
#include <string>

class Expression {
 public:
  static void set_dict() {
    dict_.clear();
    for (char i = 'A'; i <= 'Z'; ++i) dict_[i] = Random();
    for (char i = 'a'; i <= 'z'; ++i) dict_[i] = Random();
  }

  void ReadExpression() { std::getline(std::cin, expression_); }

  void ConvertToPostfix();

  int Calculate();

 protected:
  static int Random() {
    const int low = 10, high = 1000;
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(low, high);
    return distribution(generator);
  }

  static std::map<char, int> dict_;

 private:
  std::string expression_;
};

void Expression::ConvertToPostfix() {
  std::string new_expression_;
  std::stack<char> tmp_;

  for (auto&& i : expression_) {
    switch (i) {
      case ' ':
      case '\t':
        break;
      case '(':
        tmp_.push('(');
        break;
      case ')':
        while (tmp_.top() != '(') {
          new_expression_ += tmp_.top();
          tmp_.pop();
        }
        tmp_.pop();
        break;
      case '+':
      case '-':
      case '*':
        while (!tmp_.empty() && tmp_.top() != '(') {
          new_expression_ += tmp_.top();
          tmp_.pop();
        }
        tmp_.push(i);
        break;
      default:
        new_expression_ += i;
        break;
    }
  }

  while (!tmp_.empty()) {
    new_expression_ += tmp_.top();
    tmp_.pop();
  }

  expression_ = std::move(new_expression_);
}

int Expression::Calculate() {
  std::stack<int> tmp_;

  for (auto&& i : expression_) {
    switch (i) {
      case '+': {
        int num = tmp_.top();
        tmp_.pop();
        tmp_.top() += num;
        break;
      }
      case '-': {
        int num = tmp_.top();
        tmp_.pop();
        tmp_.top() -= num;
        break;
      }
      case '*': {
        int num = tmp_.top();
        tmp_.pop();
        tmp_.top() *= num;
        break;
      }
      default:
        tmp_.push(isalpha(i) ? dict_[i] : i - '0');
        break;
    }
  }

  int result_ = tmp_.top();
  tmp_.pop();
  return result_;
}

std::map<char, int> Expression::dict_;

int main() {
  size_t n;
  std::cin >> n;
  std::cin.ignore(255, '\n');

  Expression::set_dict();

  for (size_t i = 0; i < n; ++i) {
    Expression exp1, exp2;
    exp1.ReadExpression();
    exp2.ReadExpression();
    exp1.ConvertToPostfix();
    exp2.ConvertToPostfix();
    std::cout << (exp1.Calculate() == exp2.Calculate() ? "YES\n" : "NO\n");
  }

  return 0;
}
