// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // dp五部曲
    // 1-确定dp数组及下标含义
    // 2-确定dp数组初值
    // 3-确定dp数组递推方程
    // 4-确定dp数组遍历顺序
    // 5-手动推导dp数组值
    // dp[i]表示当前以nums[i]结尾的最大和的连续子数组
    // vector<int> dp(nums.size(), 0);
    vector<int> dp(2, 0);
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[1] = max(dp[0] + nums[i], nums[i]);
      res = max(res, dp[1]);
      dp[0] = dp[1];
    }
    return res;
  }
};
// @lc code=end
