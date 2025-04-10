/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
// @lc code=start
class Solution {
 public:
  int countSubstrings(string s) {
    /*
    dp五部曲：
    1.确定dp数组及下标方程
    2.确定递推方程
    3.确定dp遍历顺序
    4.确定dp初始值
    5.手动测算dp数组值
    dp[i][j]:以字符串s[i]至si[j]是否回文串

    if(s[i]!=s[j])  false;
    else {
        if(j-1<=1){
            dp[i][j]=true;
        }
        else{
            dp[i][j]=dp[i+1][j-1];
        }
    }

    if(dp[i][j])
            result+=dp[i][j]


    由递推方程看出需先遍历列再到行








    */
    int res = 0;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for (int j = 0; j < s.size(); j++) {
      for (int i = 0; i <= j; i++) {
        if (s[i] != s[j]) {
          dp[i][j] = false;
        } else {
          if (j - i <= 1) {
            dp[i][j] = true;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }
        if (dp[i][j]) {
          res += 1;
        }
      }
    }
    return res;
  }
};
// @lc code=end