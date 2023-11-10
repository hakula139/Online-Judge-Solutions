/*
 * @lc app=leetcode id=178 lang=mysql
 *
 * [178] Rank Scores
 */

-- @lc code=start
SELECT
  score,
  DENSE_RANK() OVER (
    ORDER BY
      score DESC
  ) `rank`
FROM
  Scores;
-- @lc code=end
