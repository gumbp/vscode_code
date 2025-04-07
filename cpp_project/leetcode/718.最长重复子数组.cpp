/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        // 子数组 即为连续子序列
        // dp五部曲
        // 1.确定dp数组含义及初值
        // 2.确定dp数组
        // 3.确定dp递推方程
        // 4.确定dp遍历顺序
        // 5.手动推算dp数组的值
        // dp[i][j]表示以nums1[i-1]结尾的序列和以nums2[j-1]结尾的序列中最长公共子数组的长度
        // 显然 递推关系为dp[i][j]  由dp[i-1][j-1]得出

        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        int res = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i-1] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (res <= dp[i][j])
                {
                    res = dp[i][j];
                }
            }
        }
        return res;
    }
};
// @lc code=end