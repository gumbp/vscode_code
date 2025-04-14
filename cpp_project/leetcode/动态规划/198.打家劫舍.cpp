/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
// @lc code=start
class Solution {
 public:
  int rob(vector<int> &nums) {
    // dp五部曲
    // 1-确定dp数组及下标的含义
    // 2-确定dp数组的初值
    // 3-确定递推方程
    // 4-确定遍历顺序
    // 5-举例推导dp数组的初值

    vector<int> dp(nums.size() + 1, 0);
    // dp[i]表示在i个房屋可选的情况下，偷取到的最大价值
    // 由于不能连续窃取相邻的两家
    // 因此递推方程为：dp[i]=max(dp[i-1],dp[i-2]+nums[i])
    // 递推方程为
    dp[0] = 0;
    dp[1] = nums[0];
    // dp[2] = max(nums[0], nums[1]);
    for (int i = 2; i <= nums.size(); i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[nums.size()];
  }
};
// @lc code=end