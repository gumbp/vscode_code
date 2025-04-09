/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int currentDistance = 0;
        int nextDistance = 0;
        if (nums.size() == 1)
        {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nextDistance = max(nextDistance, i + nums[i]);
            if (i == currentDistance)
            {
                ans++;
                currentDistance = nextDistance;
                if (nextDistance >= nums.size() - 1)
                    break;
            }
        }
        return ans;
    }
};
// @lc code=end
