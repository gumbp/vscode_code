/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // 子数组 即为连续子序列
        // dp五部曲
        // 1.确定dp数组含义及初值
        // 2.确定dp数组
        // 3.确定dp递推方程
        // 4.确定dp遍历顺序
        // 5.手动推算dp数组的值
        // dp[i][j]表示 text1以text1[i-1]结尾的、text2以text2[j-1]为结尾的子序列最大的公共长度
        // 显然dp[i][j]等于多少  取决于text1[i-1]和text2[j-1]是否相等
        // 若相等 则dp[i][j]=dp[i-1][j-1]+1;不相等，则
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));

        for (int i = 1; i <= text1.size();i++){
            for (int j = 1; j <= text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
// @lc code=end
