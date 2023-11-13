#
# @lc app=leetcode id=194 lang=bash
#
# [194] Transpose File
#

# @lc code=start
awk '
{
  for (i = 1; i <= NF; i++) {
    if (FNR == 1) {
      s[i] = $i;
    } else {
      s[i] = s[i] " " $i;
    }
  }
}
END {
  for (i = 1; s[i] != ""; i++) {
    print s[i];
  }
}' file.txt
# @lc code=end
