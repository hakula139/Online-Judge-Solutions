/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */

// @lc code=start
#include <cmath>

class Solution {
 public:
  int poorPigs(int buckets, int minutes_to_die, int minutes_to_test) {
    /**
     * Suppose there are n iterations, k pigs and b buckets of liquid.
     *
     * Each pig has (n + 1) states, where each state denotes that the pig dies
     * at the i-th iteration (1 <= i <= n), and specially the (n + 1) state
     * means the pig is still alive after n iterations. So each pig contains
     * log2(n + 1) bits of information, and k pigs contain k * log2(n + 1) bits.
     *
     * On the other hand, there are b possible states of buckets to determine,
     * where each state denotes that the i-th bucket of liquid is poisonous. So
     * we need at least log2(b) bits of information.
     *
     * Hence, we have k * log2(n + 1) >= log2(b), where k is the result we need.
     *
     * For a specific encoding method, consider the following example:
     *
     * If n = 4 and k = 3, we encode {x, y, z} to be the state of the 3 pigs
     * after n iterations (1 <= x, y, z <= n + 1). So we have states ranging
     * from {1, 1, 1} to {5, 5, 5}, which means we can determine at most b = 125
     * buckets. We map each state to a bucket: {1, 1, 1} -> 1, ..., {5, 5, 5} ->
     * 125. Now we can accordingly feed the pigs with the buckets of liquid. For
     * instance, if we have a mapping of {x, y, z} -> t, we feed bucket t to pig
     * 1 at iteration x, pig 2 at iteration y, pig 3 at iteration z, and
     * specially we don't feed the bucket if the state of the pig is (n + 1).
     * By using this strategy, we know which pigs to feed with which buckets at
     * each iteration.
     */

    auto n = minutes_to_test / minutes_to_die;
    return std::ceil(std::log2(buckets) / std::log2(n + 1));
  }
};
// @lc code=end
