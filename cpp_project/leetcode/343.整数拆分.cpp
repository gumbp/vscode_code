/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
// @lc code=start

// 递归五部曲
// 1-确定dp数组及其下标含义
// 确定dp数组初值
// 确定递推关系
// 确定dp遍历顺序
// 举例推导dp数组值

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
// @lc code=end