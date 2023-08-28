// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1002.h"
#include <algorithm>
using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */
// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        if (words.size() == 0)
        {
            return {};
        }
        vector<string> res;
        vector<int> hash_array(26, 0);
        vector<int> hash_array1(26, 0);
        // 以第一个字符串每个字符出现的频率作为hash_array的初始值
        for (int i = 0; i < words[0].size(); i++)
        {
            hash_array[words[0][i] - 'a'] += 1;
        }
        for (int i = 1; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                hash_array1[words[i][j] - 'a'] += 1;
            }
            for (int j = 0; j < 26; j++)
            {
                // 每次hash_array表中保留的是每个字符出现的最小次数
                hash_array[j] = min(hash_array[j], hash_array1[j]);
            }
            hash_array1.clear();
            hash_array1.assign(26, 0);
        }
        for (int j = 0; j < 26; j++)
        {
            if (hash_array[j] > 0)
            {
                while (hash_array[j] > 0)
                {
                    int temp = j + 'a';
                    char temp1 = static_cast<char>(temp);
                    res.push_back(string(1,temp1));
                    hash_array[j]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
