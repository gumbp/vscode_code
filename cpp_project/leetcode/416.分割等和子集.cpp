/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution
{
    // 递归五部曲
    // 1-确定dp数组及其下标含义
    // 2-确定dp数组初值
    // 3-确定递推关系
    // 4-确定dp遍历顺序
    // 5-举例推导dp数组值
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return false;
        }
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }
        int target_sum = sum / 2;
        if (sum % 2)
        {
            return false;
        }
        vector<int> dp(target_sum + 1, 0);
        dp[0] = 0;

        // 外层循环先遍历每一个元素
        for (int i = 0; i < nums.size(); i++)
        {
            // 内层循环遍历“和值 从1到 总值一半的过程”
            // 至于为什么倒序遍历 本质还是防止一个元素重复选取
            // 如果顺序遍历，递推方程中：dp[j - nums[i]]可能包含了选取第i个物品
            // 的情况，那么后面再加上nums[i],无疑是重复选取了i元素
            // 相反，如果倒序遍历，那么递推方程中的是不可能出现已经选取了物品i
            // 的情况，因为是倒序遍历，所以dp[j - nums[i]]在本轮外层循环中还没更新，本质还是上一轮选取第i-1个元素
            // 时的情况，因而不可能包含选取第i个的元素的情况，因此后面再加上物品i，是不会造成重复的
            for (int j = target_sum; j >= 1; j--)
            {
                if (nums[i] <= j)
                {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
        }
        bool res = dp[target_sum] == target_sum ? true : false;
        return res;
    }
};
// @lc code=end
