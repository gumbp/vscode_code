/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
// 1-确定dp数组及下标含义
// 2-确定dp数组初值
// 3-确定递推关系
// 4-确定遍历顺序
// 5-举例推导dp数组

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
      return 0;
    }
    dp[0][0] = 1;

    // 初始化第一行和第一列
    for (int i = 1; i < n; i++) {
      dp[0][i] = (obstacleGrid[0][i] == 1) ? 0 : dp[0][i - 1];
    }

    for (int i = 1; i < m; i++) {
      dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
          continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }

  // 优化空间  一维滚动数组
  //     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  //     if (obstacleGrid[0][0] == 1)
  //         return 0;
  //     vector<int> dp(obstacleGrid[0].size());
  //     for (int j = 0; j < dp.size(); ++j)
  //         if (obstacleGrid[0][j] == 1)
  //             dp[j] = 0;
  //         else if (j == 0)
  //             dp[j] = 1;
  //         else
  //             dp[j] = dp[j-1];

  //     for (int i = 1; i < obstacleGrid.size(); ++i)
  //         for (int j = 0; j < dp.size(); ++j){
  //             if (obstacleGrid[i][j] == 1)
  //                 dp[j] = 0;
  //             else if (j != 0)
  //                 dp[j] = dp[j] + dp[j-1];
  //         }
  //     return dp.back();
  // }
};
// @lc code=end
