/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.size()<=1){
            return strs[0];
        }
        int min_len = 0xffffffff;//记录strs数组中长度最短的元素 以他为匹配基准
        int j = 0;//记录strs数组中最短元素在数组中的下标
        for (auto i = 0; i < strs.size(); i++)
        {
            if (strs[i].size() < min_len)
            {
                min_len = strs[i].size();
                j = i;
            }
        }
        string match_pre = "";
        for (auto i = 0; i < min_len; i++)
        {
            for (auto k = 0; k < strs.size(); k++)
            {
                if (strs[k][i] != strs[j][i])
                {
                    return match_pre;
                }
            }
            match_pre += strs[j][i];
        }
        return match_pre;
    }
};
// @lc code=end
