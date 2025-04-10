/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // dp五部曲
        // 1-确定dp数组及下标含义
        // 2-确定dp递推方程
        // 3-确定dp数组初值含义
        // 4-确定dp递推 方程
        // 5-手动推导dp数组值
        vector<size_t> dp(target + 1, 0);
        dp[0] = 1;
        // 由于是考虑组合数，且为完全背包问题
        // 那么外层for循环必须先遍历target值，由小到小
        // 内层遍历数组的各元素值，这样才能确保每一个目标值的组合数都能重复使用到所有元素，且包含不同排列的组合方式
        for (int j = 1; j <= target; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (j >= nums[i])
                {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
