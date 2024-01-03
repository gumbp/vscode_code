/*
 * @Author: Mr.Gan 
 * @Date: 2024-01-02 13:00:27 
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2024-01-02 14:04:44
 */
// @before-stub-for-debug-begin
#include "commoncppproblem131.h"
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> single_res;
    void partition(string &s, int start)
    {
        int n = s.length();
        if (start == n)
        {
            res.push_back(single_res);
        }
        else
        {
            for (int i = start; i < n; i++)
            {
                // 若start到i这段子串为回文串  则将其记录single_res中
                if (isPalindrome(s, start, i))
                {
                    single_res.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1);
                    single_res.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        partition(s, 0);
        return res;
    }
};
// @lc code=end