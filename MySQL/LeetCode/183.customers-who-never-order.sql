/*
 * @lc app=leetcode id=183 lang=mysql
 *
 * [183] Customers Who Never Order
 */

-- @lc code=start
SELECT
  name Customers
FROM
  Customers
WHERE
  id NOT IN (
    SELECT
      customerId
    FROM
      Orders
  );
-- @lc code=end
