#
# @lc app=leetcode id=193 lang=bash
#
# [193] Valid Phone Numbers
#

# @lc code=start
grep -P "^\(\d{3}\) \d{3}-\d{4}$|^\d{3}-\d{3}-\d{4}$" file.txt
# @lc code=end
