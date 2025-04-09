/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
// @lc code=start
// class Solution
// {
// public:
//     vector<int> partitionLabels(string s)
//     {
//         vector<int> res;
//         int length;
//         map<char, int> last_appear;
//         // 统计每一个字符最后出现的位置
//         for (int i = 0; i < s.size(); i++)
//         {
//             last_appear[s[i]] = i;
//         }
//         int start = 0;
//         int end = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             end = max(end, last_appear[s[i]]);
//             if (end == i)
//             {
//                 res.push_back(end - start + 1);
//                 // +1是因为for循环后i会自加1  实际下一片段的起点为i+1
//                 start = i + 1;
//             }
//         }
//         return res;
//     }
// };

// 使用固定数组大小  优化空间复杂度和查找的时间复杂度
class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        int hash[27] = {0}; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < S.size(); i++)
        { // 统计每一个字符最后出现的位置
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++)
        {
            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
// @lc code=end
