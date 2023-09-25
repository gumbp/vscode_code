/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
// @lc code=start
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> res;
        int i = -1;
        int n = tokens.size();
        int ultimate_res = 0;
        while (++i < n)
        {
            if (tokens[i] == "+")
            {
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                ultimate_res = (b + a);
                res.push(ultimate_res);
            }
            else if (tokens[i] == "-")
            {
                int a = (res.top());
                res.pop();
                int b = (res.top());
                res.pop();
                ultimate_res = (b - a);
                res.push(ultimate_res);
            }
            else if (tokens[i] == "*")
            {
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                ultimate_res = (b * a);
                res.push(ultimate_res);
            }
            else if (tokens[i] == "/")
            {
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                ultimate_res = (b / a);
                res.push(ultimate_res);
            }
            else
            {
                res.push(stoi(tokens[i]));
            }
        }
        return res.top();
    }
};
// @lc code=end
