/*
 * @lc app=leetcode id=176 lang=mysql
 *
 * [176] Second Highest Salary
 */

-- @lc code=start
SELECT
  MAX(salary) AS SecondHighestSalary
FROM
  Employee
WHERE
  salary NOT IN (
    SELECT
      MAX(salary)
    FROM
      Employee
  );
-- @lc code=end
