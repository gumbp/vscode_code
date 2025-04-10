/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
// @lc code=start
class Solution {
 public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    int a = robRange(nums, 0, nums.size() - 2);
    int b = robRange(nums, 1, nums.size() - 1);
    return max(a, b);
  }

  int robRange(vector<int> &nums, int start, int end) {
    // dp五部曲
    // 1-确定dp数组及下标含义
    // 2-确定dp数组初值
    // 3-确定dp递推方程
    // 4-确定遍历顺序
    // 5-举例推导dp数组的值
    // dp[i]表示在i个房间上窃取的最大价值
    // dp[0]=0;
    // 递推方程
    // dp[i]=max(dp[i-1],dp[i-2]+nums[i])
    // 思路：
    // dp[i]决定的是当前第i间房到底偷不偷，若偷，则前一间房不能偷；即：dp[i]=dp[i-2]+nums[i]
    // 若不偷，则dp[i]=dp[i-1];
    // 二者取最大值
    // 假设当前有n+1间房子，
    // 又二者是个循环
    // 则1、偷了第一间,就不能偷最后一间和第二间,相当于只考虑房子从0到n-1的情况
    // 2、若第一间不在选取范围内，从第二间偷取，则房子的考虑范围为1-n
    if (start == end) {
      return nums[end];
    }
    vector<int> dp(nums.size());
    dp[start] = nums[start];
    dp[start + 1] = max(dp[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[end];
  }
};
// @lc code=end