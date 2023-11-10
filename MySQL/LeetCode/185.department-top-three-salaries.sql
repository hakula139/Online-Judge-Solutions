/*
 * @lc app=leetcode id=185 lang=mysql
 *
 * [185] Department Top Three Salaries
 */

-- @lc code=start
SELECT
  Department,
  Employee,
  Salary
FROM
  (
    SELECT
      D.name Department,
      E.name Employee,
      E.salary Salary,
      DENSE_RANK() OVER (
        PARTITION BY
          E.departmentId
        ORDER BY
          E.salary DESC
      ) `Rank`
    FROM
      Employee E
      JOIN Department D ON E.departmentId = D.id
  ) Sorted
WHERE
  `Rank` <= 3;
-- @lc code=end
