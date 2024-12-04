/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // dp五部曲
        // 1-确定dp数组下下标的含义
        // 2-确定dp数组初值
        // 3-确定递推方程
        // 4-确定遍历顺序
        // 5-举例推导dp数组的值
        // dp[k]表示可以凑成金额为k的最少硬币数目
        // 显然dp[k]=min(dp[k],dp[k-value[i]])
        // 这里是求组合数，外层循环先遍历物品，内层循环遍历背包

        // 我的版本  时间较慢
        //     if(amount<=0){
        //         return 0;
        //     }
        //     vector<int> dp(amount + 1, 0);
        //     // 表示组成0元的最少硬币数为0
        //     dp[0] = 0;
        //     for (int j = 0; j <= amount; j++)
        //     {
        //         for (int i = 0; i < coins.size(); i++)
        //         {
        //             if (j < coins[i])
        //             {
        //                 continue;
        //             }
        //             else if (j == coins[i])
        //             {
        //                 dp[j] = 1;
        //                 break;
        //             }
        //             else if (dp[j] != 0 && dp[j - coins[i]] != 0)
        //             {

        //                 dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        //             }
        //             else
        //             {
        //                 dp[j] = dp[j - coins[i]] > 0 ? dp[j - coins[i]] + 1 : dp[j];
        //             }
        //         }
        //     }
        //     if (dp[amount] == 0)
        //     {
        //         return -1;
        //     }
        //     return dp[amount];
        //

        // 简洁版
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        // 表示组成0元的最少硬币数为0
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
        {
            return -1;
        }
        return dp[amount];
    }
};
// @lc code=end