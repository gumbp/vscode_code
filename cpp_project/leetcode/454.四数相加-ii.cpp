/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
//思路  四数之和化为两数之和
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int count = 0;
        unordered_map<int, int> my_map;
        for (const auto &it : nums1)
        {
            for (const auto &it1 : nums2)
            {
                my_map[it + it1]++;
            }
        }

        for (const auto &it : nums3)
        {
            for (const auto &it1 : nums4)
            {
                int target = -(it + it1);
                if (my_map.count(target))//count函数用于返回哈希表中是否存在键为target的成员  是返回1  否返回0
                {
                    count += my_map[target];
                }
            }
        }
        return count;
    }
};
// @lc code=end
