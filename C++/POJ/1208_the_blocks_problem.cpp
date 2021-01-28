#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class BlockWorld {
 public:
  BlockWorld() {}
  explicit BlockWorld(size_t n) {
    world_.reserve(n);
    pos_.reserve(n);
    for (int i = 0; i < n; ++i) {
      world_.push_back(std::vector<int>{i});
      pos_.push_back(i);
    }
  }

  void Operate() {
    std::string cmd1, cmd2;
    int from, to;
    while (true) {
      std::cin >> cmd1;
      if (cmd1 == "quit") break;
      std::cin >> from >> cmd2 >> to;
      if (from == to) continue;              // Invalid operation
      if (pos_[from] == pos_[to]) continue;  // Invalid operation
      if (cmd1 == "move") {
        ReturnBlocks(pos_[from], from);
        if (cmd2 == "onto") ReturnBlocks(pos_[to], to);
        Move(from, to);
      } else if (cmd1 == "pile") {
        if (cmd2 == "onto") ReturnBlocks(pos_[to], to);
        Pile(pos_[from], from, to);
      }
    }
  }

  void ReturnBlocks(int pile_pos, int block) {
    int block_moving;
    while ((block_moving = world_[pile_pos].back()) != block) {
      world_[block_moving].push_back(block_moving);
      pos_[block_moving] = block_moving;
      world_[pile_pos].pop_back();
    }
  }

  void Move(int from, int to) {
    world_[pos_[to]].push_back(from);
    world_[pos_[from]].pop_back();
    pos_[from] = pos_[to];
  }

  void Pile(int pile_pos, int from, int to) {
    auto end_pos = world_[pile_pos].end();
    auto start_pos = std::find(world_[pile_pos].begin(), end_pos, from);
    for (auto i = start_pos; i < end_pos; ++i) {
      world_[pos_[to]].push_back(*i);
      pos_[*i] = pos_[to];
    }
    world_[pile_pos].erase(start_pos, end_pos);
  }

  void Output() {
    size_t n = world_.size();
    for (int i = 0; i < n; ++i) {
      std::cout << i << ':';
      for (auto&& j : world_[i]) std::cout << ' ' << j;
      std::cout << '\n';
    }
  }

 protected:
  std::vector<std::vector<int>> world_;
  std::vector<int> pos_;
};

int main() {
  size_t n;
  std::cin >> n;
  BlockWorld world(n);
  world.Operate();
  world.Output();
  return 0;
}
