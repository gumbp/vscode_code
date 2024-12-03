/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int mini_jumbp = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // mini_jumbp自加表示：从当前位置到达末尾所需最小跳数，比上一步到达末尾所需最小跳数多1跳
            // 因为是从后往前遍历
            mini_jumbp++;
            if (nums[i] >= mini_jumbp)
            {
                // mini_jumbp赋0表示 从当前位置可以到达末尾位置
                mini_jumbp = 0;
            }
        }

        // for循环结束，若第一个位置的跳数大于等于所需最小跳数，即mini_jumbp被赋为0
        // 则表示可以从第一个位置到达终点，返回true
        if (mini_jumbp == 0)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
