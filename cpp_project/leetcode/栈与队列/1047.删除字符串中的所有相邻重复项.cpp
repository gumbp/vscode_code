// @before-stub-for-debug-begin
#include "commoncppproblem1047.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @Author: Mr.Gan
 * @Date: 2023-09-16 22:09:12
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-19 16:59:03
 */
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
// @lc code=start
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> res;
        int i = 0;
        int n = s.length();
        while (i < n)
            {
                while (!res.empty() && res.top() == s[i])
                {
                    i++;
                    res.pop();
                }
                if (i < n)
                {
                    res.push(s[i]);
                    i++;
                }
            }
        s.clear();
        if (res.empty())
        {
            return "";
        }
        while (!res.empty())
        {
            s += res.top();
            res.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end