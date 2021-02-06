#include <algorithm>
#include <vector>

using std::min;
using std::sort;
using std::vector;

class Solution {
 public:
  int coinChange(const vector<int>& coins, int amount) {
    result_ = vector<int>(amount + 1);
    coins_ = coins;
    sort(coins_.begin(), coins_.end());
    return CoinChange(amount);
  }

 private:
  vector<int> result_;
  vector<int> coins_;

  int CoinChange(int amount) {
    if (amount < 0) return -1;
    if (amount == 0) return 0;
    auto min_result = amount + 1;
    for (auto coin : coins_) {
      if (coin > amount) break;
      auto cache = result_[amount - coin];
      auto count = cache ? cache : CoinChange(amount - coin);
      if (count == -1) continue;
      min_result = min(min_result, ++count);
    }
    result_[amount] = (min_result != amount + 1) ? min_result : -1;
    return result_[amount];
  }
};
