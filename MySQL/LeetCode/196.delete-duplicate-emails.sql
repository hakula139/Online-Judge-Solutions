/*
 * @lc app=leetcode id=196 lang=mysql
 *
 * [196] Delete Duplicate Emails
 */

-- @lc code=start
DELETE P1
FROM
  Person P1,
  Person P2
WHERE
  P1.email = P2.email
  AND P1.id > P2.id;
-- @lc code=end
