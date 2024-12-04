/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        // dp五部曲
        // 1-确定dp数组及下标含义
        // 2-确定dp数组初值
        // 3-确定dp递推关系
        // 4-确定for循环的遍历顺序
        // 5-举例推导dp数组的值
        vector<int> dp(n + 1, INT_MAX);
        // dp[i]表示整数i中和为i的完全平方数的最少数量
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end