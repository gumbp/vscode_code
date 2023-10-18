/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-16 09:39:31 
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-16 09:41:19
 */
// @before-stub-for-debug-begin
#include "commoncppproblem151.h"
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
// @lc code=start
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> res;
        string str;
        int i = 0;
        while (i < s.size())
        {
            while (s[i] == ' ' && i < s.size())
            {
                i++;
            }
            while (s[i] != ' ' && i < s.size())
            {
                str += s[i];
                i++;
            }
            if (!str.empty())
            {
                res.push(str);
            }
            str.clear();
        }
        s.clear();
        while (!res.empty())
        {
            s += res.top();
            res.pop();
            if (!res.empty())
            {
                s += " ";
            }
        }
        return s;
    }
};
// @lc code=end