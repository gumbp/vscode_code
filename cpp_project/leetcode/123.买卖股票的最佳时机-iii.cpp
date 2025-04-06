/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (!prices.size())
        {
            return 0;
        }
        //    buy1表示第一次股票买耗费的成本
        int buy1 = INT_MAX;
        //    profit1表示第一次抛出时获得的最大利润
        int profit1 = INT_MIN;

        int buy2 = INT_MAX;
        int profit2 = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
        {
            // 第一次买入的两种选择：1.不买入当前价格的股票，维持之前；
            // 2.买入当前价格的股票，计算成本，二者取最小值
            buy1 = min(buy1, prices[i]);

            // 第一次卖出股票的两种选择：1.不以当前价格卖出股票，维持原来
            // 2.以当前价格第一次卖出股票，并计算收益，二者取最大值
            profit1 = max(profit1, prices[i] - buy1);

            // 第二次买入的两种选择：1.不买入当前股票，维持之前第二次买入的选择状态；
            // 2.买入当前价格的股票
            buy2 = min(buy2, prices[i] - profit1);

            // 第二次卖出的两种选择：1.不以当前价格卖出股票，维持原来利润
            // 2.以当前价格第二次卖出股票，并计算最新利润
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};
// @lc code=end