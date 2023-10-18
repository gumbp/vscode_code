/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-15 08:22:08 
 * @Last Modified by:   Mr.Gan 
 * @Last Modified time: 2023-09-15 08:22:08 
 */
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        vector<int> next(n + 1, 0);
        // j表示前缀最后一个字符  i表示后缀最后一个字符
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = next[j];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i + 1] = j;
        }
        return next[n] > 0 && n % (n - next[n]) == 0;
    }
};
// @lc code=end