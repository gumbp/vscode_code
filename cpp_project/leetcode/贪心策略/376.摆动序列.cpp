/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    // 好牛逼啊这思想  还得是dp
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        int peak = 1;
        int valley = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                peak = valley + 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                valley = peak + 1;
            }
        }
        return max(peak, valley);
    }
};
// @lc code=end