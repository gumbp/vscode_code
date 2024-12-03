/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // 动态规划算法
        // dp五部曲
        // 1- 确定dp数组及其下标的含义
        // 2- 确定递推公式
        // 3- dp数组如何初始化
        // 4- 确定遍历顺序
        // 5- 举例推导dp数组
        if (cost.size() == 1)
        {
            return cost[0];
        }
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        // dp[i]表示上到第i级台阶所需要的最小代价
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};
// @lc code=end