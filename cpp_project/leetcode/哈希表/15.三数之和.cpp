/*
 * @Author: Mr.Gan
 * @Date: 2023-09-16 09:48:25
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-16 09:56:07
 */
// @before-stub-for-debug-begin
#include "commoncppproblem15.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
// 大致思路：先给数组排序，从所有负数元素中依次列举，作为三数之和的首个元素pre_element，
//  因为数组排过序,当pre_element为正数时，表明后序不会再有满足条件的两个元素
// 表明此时遍历结束
// pre_element<0时，定义双指针指向pre_element的后序元素首尾，依次判断当前双指针元素之和是否为pre_element的相反数
//  若是  则满足三元组，放入结果数组中。去重后继续循环
//  否则  依据该和与pre_element的相反数的大小关系  调整双指针的左移和右移
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        if (nums[0] > 0)
        {
            return {};
        }
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            // i>0 确保从第二个数开始判断是否重复出现过
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int target = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    // while循环确保去重  当结束循环时  nums[j+1]与nums[j]不等
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    // 当结束循环时 nums[k]!=nums[k-1]
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    // nums[j] nums[k]仍为旧值  更新
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
