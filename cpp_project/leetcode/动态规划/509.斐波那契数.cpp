/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    // dp五部曲
    // 1- 确定dp数组及其下标的含义
    // 2- 确定递推公式
    // 3- dp数组如何初始化
    // 4- 确定遍历顺序
    // 5- 举例推导dp数组


// 时间复杂度：O(n);空间复杂度：O(n)
    // int fib(int n)
    // {
    //     if (n <= 1)
    //     {
    //         return n;
    //     }
    //     vector<int> dp(n + 1, 0);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; i++)
    //     {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }

    // 更优化的代码 时间复杂度：O(n);空间复杂度：O(1)
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        int current = 1;
        int pre_key = 0;
        for (int i = 2; i <= n; i++)
        {
            int temp = current;
            current = current + pre_key;
            pre_key = temp;
        }
        return current;
    }
};
// @lc code=end
