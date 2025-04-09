/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int sum = 0;
    int smax = INT_MIN;
    for (int num : nums) {
      sum += num;
      smax = max(smax, sum);
      // 若当前和为负数，则重置sum为0，因为无论下一个元素为正为负，
      // 因为之前和为负，将当前和置为0，便于筛选后续的连续子序列的新最大值，故重置为0
      if (sum < 0) {
        sum = 0;
      }
    }
    return smax;
  }
};
// @lc code=end
