/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */
// @lc code=start
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        // dp五部曲
        // 1.确定dp数组含义及初值
        // 2.确定dp数组
        // 3.确定dp递推方程
        // 4.确定dp遍历顺序
        // 5.手动推算dp数组的值
        // dp[i][j]表示以nums1[i-1]结尾的nums1和以nums2[j-1]结尾的nums2中的最大连线数目
        // 本地跟求最长公共子序列完全相同  只是换了个说法
        // 递推关系

        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
// @lc code=end