/*
 * @lc app=leetcode id=262 lang=mysql
 *
 * [262] Trips and Users
 */

-- @lc code=start
SELECT
  request_at Day,
  ROUND(SUM(T.status != 'completed') / COUNT(*), 2) 'Cancellation Rate'
FROM
  Trips T
  JOIN Users C ON T.client_id = C.users_id
  AND C.banned = 'NO'
  JOIN Users D ON T.driver_id = D.users_id
  AND D.banned = 'NO'
WHERE
  request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY
  request_at;
-- @lc code=end
