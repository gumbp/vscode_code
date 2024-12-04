/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    // 递归方法  超时
    // int climbStairs(int n) {
    //     if(n==1){
    //         return 1;
    //     }
    //     if(n==2){
    //         return 2;
    //     }
    //     return climbStairs(n - 1) + climbStairs(n - 2);
    // }

    // 动态规划算法
    // dp五部曲
    // 1- 确定dp数组及其下标的含义
    // 2- 确定递推公式
    // 3- dp数组如何初始化
    // 4- 确定遍历顺序
    // 5- 举例推导dp数组

    int climbStairs(int n)
    {
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }

        vector<int> dp(n + 1, 0);
        // dp[i]表示走到第i级台阶有dp[i]中走法
        // 递推方程为：dp[i]=dp[i-2]*2+dp[i-1];
        // 这里走到第n-2级台阶时直接跳两步走到n，这是因为如果一步一步走，就变为了走到第n-1级台阶的情况
        // 与之后考虑的情况重复，造成结果冗余
        // 表示走n级台阶的走法等于（走到n-1级台阶的走法1加上走到n-2级台阶的走法）

        // dp初始值
        dp[1] = 1;//走一级台阶只有一种走法
        dp[2] = 2;//走两级台阶有两种走法
        for (int i = 3; i <= n;i++){
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};
// @lc code=end
