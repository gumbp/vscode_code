/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
// dp五部曲
// 1- 确定dp数组及其下标的含义
// 2- 确定递推公式
// 3- dp数组如何初始化
// 4- 确定遍历顺序
// 5- 举例推导dp数组
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[i][j]表示走到[i,j]位置共有多少条路径
        // 当前一步 可以是上一步向下走得来 也可以是由上一步向右走
        // 所以dp[i][j]=dp[i][j-1]+dp[i-1][j]

        // 对于任意的dp[i][1],都只有一种方法走到，所以任意dp[i][1]=1
        // 同理  任意dp[1][i]=1
        for (int i = 1; i <= m; i++)
        {
            dp[i][1] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                // if(i==1||j==1){
                //     continue;
                // }
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end