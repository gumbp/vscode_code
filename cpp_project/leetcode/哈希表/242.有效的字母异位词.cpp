// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem242.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        map<char, int> my_map;
        map<char, int> my_map1;
        for (int i = 0; i < s.size(); i++)
        {
            my_map[s[i]] += 1;
            my_map1[t[i]] += 1;
        }
        if (my_map.size() != my_map1.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (my_map[s[i]] != my_map1[s[i]])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
