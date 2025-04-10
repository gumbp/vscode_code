/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution
{
public:
    //dp五部曲：
    // 1-确定dp数组及下标含义
    // 2-确定dp数组初值
    // 3-确定dp递推方程
    // 4-确定遍历顺序
    // 5-手动推导dp数组初值
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        // dp[i][0]表示第i天不持有股票的最大收益
        // dp[i][1]表示第i天持有股票的最大收益

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size();i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};
// @lc code=end