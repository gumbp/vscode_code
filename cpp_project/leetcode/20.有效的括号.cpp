/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-16 22:09:07 
 * @Last Modified by:   Mr.Gan 
 * @Last Modified time: 2023-09-16 22:09:07 
 */
// @before-stub-for-debug-begin
#include "commoncppproblem20.h"
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
// @lc code=start
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> result;
        int length = s.size();
        if (length % 2)
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                result.push(s[i]);
                continue;
            }
            if (result.empty())
            {
                return false;
            }
            char temp1 = result.top();
            char temp2;
            if (s[i] == ')')
            {
                temp2 = '(';
            }
            else if (s[i] == ']')
            {
                temp2 = '[';
            }
            else
            {
                temp2 = '{';
            }

            if (temp1 != temp2)
            {
                return false;
            }
            else
            {
                result.pop();
            }
        }
        if (!result.empty())
        {
            return false;
        }
        return true;
    }
};
// @lc code=end