/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // dp五部曲
        // 1-确定dp数组及下标含义
        // 2-确定dp数组初值
        // 3-确定dp递推方程
        // 4-确定递推顺序
        // 5-手动推导
        vector<int> dp(nums.size(), 1);
        // dp[i]表示长度为i的序列中最大的严格递增的子序列长度
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > result)
            {
                result = dp[i];
            }
        }
        // return dp[nums.size() - 1];
        return result;
    }
};
// @lc code=end