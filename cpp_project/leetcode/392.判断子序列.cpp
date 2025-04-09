/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // t是大串
        if(t.size()<s.size()){
            return false;
        }
        // dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size()+1, 0));
        for (int i = 1; i <= s.size();i++){
            for (int j = 1; j <= t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if(dp[s.size()][t.size()] == s.size()){
            return true;
        }
        return false;
    }
};
// @lc code=end