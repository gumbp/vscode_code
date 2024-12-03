/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        //   这道题目可能我们只会想，选一个低的买入，再选个高的卖，再选一个低的买入.....循环反复。
        // 如果想到其实最终利润是可以分解的，那么本题就很容易了！
        // 如何分解呢？
        // 假如第 0 天买入，第 3 天卖出，那么利润为：prices[3] - prices[0]。
        // 相当于(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])。
        // 此时就是把利润分解为每天为单位的维度，而不是从 0 天到第 3 天整体去考虑！
        // 那么根据 prices 可以得到每天的利润序列：(prices[i] - prices[i - 1]).....(prices[1] - prices[0])。
        // 贪心策略：只收集每天的一个正利润即可
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }
};
// @lc code=end