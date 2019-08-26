#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

template <class T>
class Node {
public:
    Node() : val_(0), left_(nullptr), right_(nullptr) {}
    explicit Node(const T& val) : val_(val), left_(nullptr), right_(nullptr) {}
    Node(const T& val, Node* left, Node* right)
        : val_(val), left_(left), right_(right) {}

    friend class ExpressionTree;

private:
    T     val_;
    Node* left_;
    Node* right_;
};

class ExpressionTree {
public:
    ExpressionTree() : is_postfix_(false), root_(nullptr), tree_height_(0) {}
    ~ExpressionTree() { DeleteTree(); }

    void ReadExpression() {
        std::getline(std::cin, expression_);
        is_postfix_ = false;
    }
    bool ExpressionIsPostfix() { return is_postfix_; }
    bool InfixToPostfix();
    void PrintExpression() { std::cout << expression_ << '\n'; }

    bool   BuildTree();
    void   PrintTree();
    size_t TreeHeight() { return tree_height_; }
    void   DeleteTree() {
        DeleteTree(root_);
        tree_height_ = 0;
        output_.clear();
    }

    void SetDict();
    int  Calculate();
    void PrintResult() { std::cout << Calculate() << '\n'; }

protected:
    void Postorder(Node<char>* root) {
        if (!root) return;
        Postorder(root->left_);
        Postorder(root->right_);
        Print(root);
    }

    void Print(Node<char>* node) {
        if (!node) return;
        std::cout << node->val_;
    }

    void   InitTreeHeight() { tree_height_ = TreeHeight(root_); }
    size_t TreeHeight(Node<char>* node) {
        if (!node) return 0;
        size_t left_height  = TreeHeight(node->left_);
        size_t right_height = TreeHeight(node->right_);
        return left_height > right_height ? ++left_height : ++right_height;
    }

    void InitOutput();
    void InitOutput(Node<char>* node,
                    size_t      pos_x,
                    size_t      pos_y,
                    size_t      space_width);

    void DeleteTree(Node<char>* node) {
        if (!node) return;
        if (node->left_) DeleteTree(node->left_);
        if (node->right_) DeleteTree(node->right_);
        delete node;
    }

    void Warning() { std::cerr << "Invalid expression.\n"; }

private:
    std::string expression_;
    bool        is_postfix_;

    Node<char>* root_;
    size_t      tree_height_;
    // output[i] represents the output at the depth of i
    std::vector<std::string> output_;

    std::map<char, int> dict_;
};

bool ExpressionTree::InfixToPostfix() {
    if (ExpressionIsPostfix()) return true;

    std::string      new_expression;
    std::stack<char> tmp;
    for (auto&& i : expression_) {
        switch (i) {
            case '(': tmp.push('('); break;
            case ')':
                while (!tmp.empty() && tmp.top() != '(') {
                    new_expression += tmp.top();
                    tmp.pop();
                }
                if (tmp.empty()) return false;
                tmp.pop();
                break;
            case '+':
            case '-':
                while (!tmp.empty() && tmp.top() != '(') {
                    new_expression += tmp.top();
                    tmp.pop();
                }
                tmp.push(i);
                break;
            case '*':
            case '/':
                while (!tmp.empty() && tmp.top() != '(' &&
                       (tmp.top() == '*' || tmp.top() == '/')) {
                    new_expression += tmp.top();
                    tmp.pop();
                }
                tmp.push(i);
                break;
            default: new_expression += i; break;
        }
    }
    while (!tmp.empty()) {
        new_expression += tmp.top();
        tmp.pop();
    }

    expression_ = std::move(new_expression);
    is_postfix_ = true;
    return true;
}

bool ExpressionTree::BuildTree() {
    if (!ExpressionIsPostfix()) InfixToPostfix();
    DeleteTree();

    std::stack<Node<char>*> tmp;
    for (auto&& i : expression_) {
        switch (i) {
            case '+':
            case '-':
            case '*':
            case '/': {
                if (tmp.size() < 2) {
                    Warning();
                    return false;
                }
                auto right_child = tmp.top();
                tmp.pop();
                auto left_child = tmp.top();
                tmp.pop();
                auto parent = new Node<char>(i, left_child, right_child);
                tmp.push(parent);
                root_ = parent;
                break;
            }
            default: {
                auto new_node = new Node<char>(i);
                tmp.push(new_node);
                break;
            }
        }
    }

    InitTreeHeight();
    return true;
}

void ExpressionTree::InitOutput() {
    size_t max_height = (TreeHeight() << 1) - 1;
    size_t max_width  = (1 << TreeHeight()) - 1;
    output_ = std::vector<std::string>(max_height, std::string(max_width, ' '));

    size_t start_pos_x = (1 << (TreeHeight() - 1)) - 1;
    size_t space_width = (start_pos_x + 1) >> 1;
    try {
        InitOutput(root_, start_pos_x, 0, space_width);
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range: " << oor.what() << '\n';
        return;
    }
}

void ExpressionTree::InitOutput(Node<char>* node,
                                size_t      pos_x,
                                size_t      pos_y,
                                size_t      space_width) {
    output_.at(pos_y).at(pos_x) = node->val_;
    if (node->left_) {
        output_.at(pos_y + 1).at(pos_x - 1) = '/';
        InitOutput(node->left_, pos_x - space_width, pos_y + 2,
                   space_width >> 1);
    }
    if (node->right_) {
        output_.at(pos_y + 1).at(pos_x + 1) = '\\';
        InitOutput(node->right_, pos_x + space_width, pos_y + 2,
                   space_width >> 1);
    }
}

void ExpressionTree::PrintTree() {
    InitOutput();
    for (auto&& i : output_) {
        auto end_pos_x = i.find_last_not_of(" ");
        if (end_pos_x != std::string::npos)
            std::cout << i.substr(0, end_pos_x + 1) << '\n';
    }
}

void ExpressionTree::SetDict() {
    dict_.clear();
    size_t n;
    std::cin >> n;
    while (n--) {
        char key;
        std::cin.ignore(255, '\n');
        std::cin >> key;
        int val;
        std::cin >> val;
        dict_.insert(std::make_pair(key, val));
    }
}

int ExpressionTree::Calculate() {
    if (!ExpressionIsPostfix()) InfixToPostfix();

    std::stack<int> tmp;
    for (auto&& i : expression_) {
        switch (i) {
            case '+': {
                int num = tmp.top();
                tmp.pop();
                tmp.top() += num;
                break;
            }
            case '-': {
                int num = tmp.top();
                tmp.pop();
                tmp.top() -= num;
                break;
            }
            case '*': {
                int num = tmp.top();
                tmp.pop();
                tmp.top() *= num;
                break;
            }
            case '/': {
                int num = tmp.top();
                tmp.pop();
                tmp.top() /= num;
                break;
            }
            default: tmp.push(dict_[i]); break;
        }
    }
    int result_ = tmp.top();
    tmp.pop();
    return result_;
}

int main() {
    ExpressionTree exp;
    exp.ReadExpression();

    exp.InfixToPostfix();
    exp.PrintExpression();  // OK

    exp.BuildTree();  // OK
    exp.PrintTree();  // OK

    exp.SetDict();
    exp.PrintResult();  // OK

    return 0;
}
