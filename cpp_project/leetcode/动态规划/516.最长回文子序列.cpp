/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    // dp[i][j]表示以s[i]开头、以s[j]结尾的字符串s中的最长回文子序列长度
    // if s[i]==s[j]:
    //     dp[i][j]=dp[i+1][j-1]+1;
    // else
    //     dp[i][j]=max(dp[i+1][j],dp[i][j-1])

    // 由递推方程得出：这里选择先自左向右再自底向上，遍历才能更新dp[i][j]的值
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); i++) {
      dp[i][i] = 1;
    }

    for (int j = 0; j < s.size(); j++) {
      for (int i = j - 1; i >= 0; i--) {
        // 确保i始终为   0<=i<j
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][s.size() - 1];
  }
};
// @lc code=end