/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        for (int bill : bills)
        {
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five == 0)
                {
                    return false;
                }
                else
                {
                    five--;
                    ten++;
                }
            }
            // 如果给出的面额是20  需要找15金额
            // 优先使用大面额搭配小面额  这样灵活性更高
            else
            {
                if (five > 0 && ten > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
