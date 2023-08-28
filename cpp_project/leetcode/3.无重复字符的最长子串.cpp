// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem3.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 进行参数检查 s为空则直接返回
        if (s.length() == 0)
        {
            return 0;
        }
        map<char, int> map_s;
        int maxlen = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            int count = 1;
            map_s[s[i]] = i;
            for (int j = i + 1; j < s.length(); j++)
            {

                // 判断当前元素是否出现过，若否 则加入元素  并将count++
                if ((map_s.find(s[j]) == map_s.end()) )
                {
                    count++;
                    map_s[s[j]] = j;
                    continue;
                }
                break;
            }
            // 每轮内层for循环结束时候  清空map_s内部信息  保证新一轮滑动的时候map_s不遗留上轮信息  避免干扰
            map_s.clear();
            maxlen = maxlen > count ? maxlen : count;
        }
        return maxlen;
    }
};
// @lc code=end
