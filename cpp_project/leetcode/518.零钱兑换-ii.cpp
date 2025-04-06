/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
// @lc code=start
class Solution
{
public:
    // dp五部曲
    // 1-确定dp数组及下标含义
    // 2-确定dp的递推方程
    // 3-确定循环的遍历顺序
    // 4-确定dp数组的初值
    // 5-举例推算dp数组的值
    int change(int amount, vector<int> &coins)
    {
        vector<size_t> dp(amount + 1, 0);
        dp[0] = 1;
        // dp[i]表示金额为i的值，能有多少种硬币方法找零
        // dp[0]=1,表示只有一种方法来凑成0，那就是0元 
        // dp[i]=dp[i]+dp[i-value] 表示当前价值为i的数值的凑成办法：可以
        // 由（不选择当前硬币的组成方法）加上（选择当前硬币的组成方法）
        // 由于是完全背包问题，所以不需考虑遍历顺序
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i] <= j)
                {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end