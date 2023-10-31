/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <vector>

struct Node {
  int val;
  std::vector<Node*> neighbors;
  Node() : val(0), neighbors() {}
  explicit Node(int val) : val(val), neighbors() {}
  Node(int val, const std::vector<Node*>& neighbors)
      : val(val), neighbors(neighbors) {}
};

// @lc code=start
#include <unordered_map>

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return node;
    auto it = new_map_.find(node->val);
    if (it != new_map_.end()) return it->second;
    auto new_node = new Node{node->val};
    new_map_[node->val] = new_node;
    for (auto neighbor : node->neighbors) {
      new_node->neighbors.push_back(cloneGraph(neighbor));
    }
    return new_node;
  }

 private:
  std::unordered_map<int, Node*> new_map_;
};
// @lc code=end
