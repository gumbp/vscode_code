// @before-stub-for-debug-begin
#include "commoncppproblem9.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        else if (x < 10)
        {
            return true;
        }
        string s = to_string(x);
        int size = s.size() - 1;
        for (int i = 0, j = size; i < j; i++, j--)
        {
            if (s[j] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end