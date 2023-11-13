#
# @lc app=leetcode id=192 lang=bash
#
# [192] Word Frequency
#

# @lc code=start
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr | awk '{ print $2, $1 }'
# @lc code=end
