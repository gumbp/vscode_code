/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    // int findContentChildren(vector<int> &g, vector<int> &s)
    // {
    //     int res = 0;
    //     sort(g.begin(), g.end());
    //     sort(s.begin(), s.end());
    //     int j = 0;
    //     for (int i = 0; i < g.size(); i++)
    //     {

    //         //必须先判断是否越界再访问数据 牢记
    //         while (j < s.size() && s[j] < g[i])
    //         {
    //             j++;
    //         }
    //         if (j == s.size())
    //         {
    //             return res;
    //         }
    //         j++;
    //         res++;
    //     }

    //     return res;
    // }

    // 别人的版本  很巧妙
    // 思路：为了尽可能满足更多的小孩，应该给胃口最小的小孩分配最小的饼干，而给
    // 胃口大的小孩分配大的饼干是最优的。大尺寸的饼干既可以满足胃口大的孩子也可以满足胃口小的孩子
    // 那么大尺寸的饼干就该优先满足胃口的小孩子。

    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--)
        { // 遍历胃口
            if (index >= 0 && s[index] >= g[i])
            { // 遍历饼干
                result++;
                index--;
            }
        }
        return result;
    }
};
// @lc code=end