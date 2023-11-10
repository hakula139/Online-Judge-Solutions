/*
 * @lc app=leetcode id=180 lang=mysql
 *
 * [180] Consecutive Numbers
 */

-- @lc code=start
SELECT DISTINCT
  L1.num ConsecutiveNums
FROM
  Logs L1
  JOIN Logs L2 ON L1.id = L2.id - 1
  JOIN Logs L3 ON L2.id = L3.id - 1
WHERE
  L1.num = L2.num
  AND L2.num = L3.num;
-- @lc code=end
