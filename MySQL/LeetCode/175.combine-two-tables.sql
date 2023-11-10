/*
 * @lc app=leetcode id=175 lang=mysql
 *
 * [175] Combine Two Tables
 */

-- @lc code=start
SELECT
  Person.firstName,
  Person.lastName,
  Address.city,
  Address.state
FROM
  Person
  LEFT JOIN Address USING (personId);
-- @lc code=end
