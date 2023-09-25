// @before-stub-for-debug-begin
#include "commoncppproblem541.h"
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
// @lc code=start
// 老是没审好题，每2k个一组，反转一组中的前k个
class Solution
{
public:
    void reverse_specify_location(int i, int j, string &s)
    {
        while (i < j)
        {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    string reverseStr(string s, int k)
    {
        int end = 2 * k - 1;
        int begin = 0;
        if (k > s.size())
        {
            reverse_specify_location(0, s.size() - 1, s);
            return s;
        }
        else if (s.size() >= k && s.size() < 2 * k)
        {
            reverse_specify_location(0, k - 1, s);
            return s;
        }
        else
        {
            while ((s.size() - begin) >= (2 * k))
            {
                reverse_specify_location(begin, begin + k - 1, s);
                begin = end + 1;
                end = end + 2 * k;
            }
            if ((s.size() - begin) >= k)
            {
                reverse_specify_location(begin, begin + k - 1, s);
                return s;
            }
            else
            {
                reverse_specify_location(begin, s.size() - 1, s);
                return s;
            }
        }
    }
};
// @lc code=end
