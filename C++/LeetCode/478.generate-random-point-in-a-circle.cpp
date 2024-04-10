/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 */

// @lc code=start
#include <cmath>
#include <numbers>
#include <random>
#include <vector>

class Solution {
 public:
  Solution(double radius, double x_center, double y_center)
      : radius_{radius}, x_center_{x_center}, y_center_{y_center} {}

  std::vector<double> randPoint() {
    /**
     * Inverse transform sampling
     *
     *    cdf(r) = r^2 / R^2
     * => cdf^{-1}(r) = R * sqrt(r)
     * => r = R * sqrt(random())
     *
     * Ref: https://stackoverflow.com/a/50746409/15790580
     */
    auto r = radius_ * std::sqrt(dist_(rng_));
    auto a = 2 * std::numbers::pi * dist_(rng_);
    return {x_center_ + r * std::cos(a), y_center_ + r * std::sin(a)};
  }

 private:
  double radius_;
  double x_center_;
  double y_center_;

  std::random_device rd_;
  std::mt19937 rng_{rd_()};
  std::uniform_real_distribution<double> dist_{0, 1};
};
// @lc code=end
