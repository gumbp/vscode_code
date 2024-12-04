/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
// @lc code=start
// dp五部曲：
// 1-确定dp数组及下标含义
// 2-确定dp数组初值
// 3-确定递推公式
// 4-确定遍历顺序
// 5-举例推导dp数组值
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        // 对于有n个节点的二叉搜索树，可以任选某一节点为根节点
        // 比如选择第i个节点为根节点，则左子树结点数为i-1；右子树结点数为n-i
        // 则n个节点的bst，排列组合数为dp[n]=dp[i-1]*dp[n-i];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end