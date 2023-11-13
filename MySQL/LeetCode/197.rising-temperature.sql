/*
 * @lc app=leetcode id=197 lang=mysql
 *
 * [197] Rising Temperature
 */

-- @lc code=start
SELECT
  W1.id
FROM
  Weather W1,
  Weather W2
WHERE
  W1.recordDate = DATE_ADD(W2.recordDate, INTERVAL 1 DAY)
  AND W1.temperature > W2.temperature;
-- @lc code=end
