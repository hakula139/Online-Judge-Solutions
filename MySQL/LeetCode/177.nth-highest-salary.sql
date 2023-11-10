/*
 * @lc app=leetcode id=177 lang=mysql
 *
 * [177] Nth Highest Salary
 */

-- @lc code=start
CREATE FUNCTION getNthHighestSalary (n INT) RETURNS INT BEGIN
SET
  n = n - 1;

RETURN (
  SELECT DISTINCT
    salary
  FROM
    Employee
  ORDER BY
    salary DESC
  LIMIT
    n, 1
);

END
-- @lc code=end
