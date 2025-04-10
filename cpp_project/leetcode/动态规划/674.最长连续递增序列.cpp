/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
 public:
  int findLengthOfLCIS(vector<int> &nums) {
    // 递归五部曲
    // 1.确定dp数值及下标含义
    // 2.确定dp数组初值
    // 3.确定dp递推方程
    // 4.确定遍历顺序
    // 5.手动推导dp数组值
    vector<int> dp(nums.size(), 1);
    // dp[i]表示以nums[i]结尾的子序列中最大的严格递增个数
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] < nums[i + 1]) {
        dp[i + 1] = dp[i] + 1;
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
// @lc code=end