/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */
// @lc code=start
class Solution
{
public:
    // 回忆dp五部曲：
    // 1-确定dp数组及下标含义
    // 2-确定dp数组初值
    // 3-确定dp递推方程
    // 4-确定dp数组遍历顺序
    // 5-举例推导dp数组初值
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(3, 0));
        // dp[i][0]表示第i天持有股票的最大收益
        // dp[i][1]表示第i天不持有股票、且不在冷冻期的最大收益
        // dp[i][2]=1表示第i天不持有股票,且在冷冻期的最大收益
        // 第一天持有股票的收益为-price[0]

        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            // 当天计算出的状态是指操作完之后的状态  
            
            // 第i天持有股票的最大收益 可能是：
            // 之前就持有  或者从当天非冷冻期时买入
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 第i天不持有且非冷冻期：前一天不持有且非冷冻期  或者前一天不持有且在冷冻期
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);

            // 第i天不持有且在冷冻期：昨天持有且刚卖出去
            dp[i][2] = dp[i - 1][0]+prices[i];
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};
// @lc code=end