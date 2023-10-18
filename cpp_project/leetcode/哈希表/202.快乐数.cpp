/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
//空间复杂度优秀 但是时间复杂度堪忧,待优化！
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        int count = 0;
        while (count < 50)
        {

            string str = to_string(n);
            int sum = 0;
            for (const auto &it : str)
            {
                int temp = stoi(string(1, it));
                sum += temp * temp;
            }
            if (sum == 1)
            {
                return true;
            }
            n = sum;
            count++;
        }
        return false;
    }
};
// @lc code=end
