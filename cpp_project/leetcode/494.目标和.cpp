/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
public:
    // 思路，本质是将数组划分出两堆，两堆之差等于target,
    // 即left-right=target
    // 又left+right=sum
    // 所以left-(sum-left)=target
    // 所以left=(target+sum)/2
    // target和sum都是已知的，问题的关键在于找到和为left的最大组合数目
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // dp五部曲
        // 1-确定dp数组及下标的含义
        // 2-确定递推关系
        // 3-确定循环遍历顺序
        // 4-确定dp数组的初值
        // 5-举例推导dp数组数值


        // 现在dp[i][j]表示在0-i个数中，和等于j的组合数
        // 递推关系dp[i][j]=dp[i-1][j]+dp[i-1][j-weight[i]]
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }
        if ((target + sum) % 2 || abs(target) > sum)
        {
            return 0;
        }

        int target_weight = (target + sum) / 2;
        if (nums.size() == 1)
        {
            if (nums[0] == target || nums[0] == (-target))
            {
                return 1;
            }
            return 0;
        }

        vector<int> dp(target_weight + 1, 0);
        // 初始化dp[0]为1，表示和为0的方法只有一种，那就是不放
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target_weight; j >= nums[i]; j--)
            {
                dp[j] = dp[j]+dp[j - nums[i]];
            }
        }
        return dp[target_weight];
    }
};
// @lc code=end