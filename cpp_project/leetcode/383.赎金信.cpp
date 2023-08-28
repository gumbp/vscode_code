// @before-stub-for-debug-begin
#include "commoncppproblem383.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
        {
            return false;
        }

        unordered_map<char, int> my_map;
        for (auto it : magazine)
        {
            my_map[it]++;
        }

        // 优化版
        for (auto it : ransomNote)
        {
            if (--my_map[it] < 0)
            {
                return false;
            }
        }

        // for (auto it : ransomNote)
        // {
        //     if (my_map.count(it) && my_map[it])
        //     {
        //         my_map[it]--;
        //         continue;
        //     }
        //     return false;
        // }
        return true;
    }
};
// @lc code=end
