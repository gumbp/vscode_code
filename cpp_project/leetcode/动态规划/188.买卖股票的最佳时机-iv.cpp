/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        // dp[i][0]表示不操作
        // dp[i][1]表示在第i天的时候第一次持有
        // dp[i][2]表示在第i天的时候第一次抛售
        // dp[i][3]表示在第i天的时候第二次持有
        // dp[i][4]表示在第i天的时候第二次抛售
        // ........
        // dp[i][2k-1]表示在第i天的时候第k次持有
        // dp[i][2k]表示在第i天的时候第k次抛售

        // 由此得知 j为奇数的时候为持有，偶数的时候为抛出

        // 初始化
        dp[0][0] = 0;
        for (int i = 1; i <= 2 * k; i += 2)
        {
            dp[0][i] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][2 * j - 1] = max(dp[i - 1][2 * j - 1], dp[i - 1][2 * j-2] - prices[i]);
                dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};
// @lc code=end