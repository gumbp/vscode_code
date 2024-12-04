/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
// @lc code=start
class Solution
{
public:
    // dp五部曲
    // 1-确定dp数组及下标含义
    // 2-确定dp的递推关系
    // 3-确定dp数组初值
    // 4-确定dp的遍历逻辑
    // 5-举例推导dp数组的值
    // dp[i][j]表示最多有i个0和j个1的子集数目
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string &str : strs)
        {
            int zeros = count(str.begin(), str.end(), '0');
            int ones = str.size() - zeros;
            for (int i = m; i >= zeros; --i)
            {
                for (int j = n; j >= ones; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end