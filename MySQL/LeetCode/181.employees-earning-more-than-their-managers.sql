/*
 * @lc app=leetcode id=181 lang=mysql
 *
 * [181] Employees Earning More Than Their Managers
 */

-- @lc code=start
SELECT
  E.name Employee
FROM
  Employee E
  JOIN Employee M ON E.managerId = M.id
WHERE
  E.salary > M.salary;
-- @lc code=end
