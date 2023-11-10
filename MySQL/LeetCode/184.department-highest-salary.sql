/*
 * @lc app=leetcode id=184 lang=mysql
 *
 * [184] Department Highest Salary
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
      RANK() OVER (
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
  `Rank` = 1;
-- @lc code=end
