/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // dp五部曲
        // 1-确定dp数组及下标含义
        // 2-确定dp数组初值
        // 3-确定dp递推方程
        // 4-确定遍历顺序
        // 5-举例推导dp数值的值
        vector<vector<int>> dp(prices.size(), vector(2, 0));
        // dp[i][0]表示第i天持有股票的收益，
        // dp[i][1]表示第i天不持有股票的收益
        // 每次二者取最大值
        // 初始化为
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            // 整个过程  只进行一次股票持有和股票抛售
            // 递推关系如下；
            // 第i天持有股票，可能是第i天买入，也可能是之前买入，最大收益取最大值
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            // 第i天不持有股票  可能是维持之前未持有的状态，也可能是之前持有，今天抛售，最大收益取二者最大值
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};
// @lc code=end