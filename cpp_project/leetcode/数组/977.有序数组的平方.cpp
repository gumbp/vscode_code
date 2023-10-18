// @before-stub-for-debug-begin
#include "commoncppproblem977.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        if (!nums.size())
        {
            return {};
        }
        int i = 0;
        int length = nums.size();
        for (; i < length; i++)
        {
            if (nums[i] >= 0)
            {
                break;
            }
        }
        // 全为大于零的数
        if (i == 0)
        {
            for (int i = 0; i < length; i++)
            {
                nums[i] *= nums[i];
            }
        }
        // 全为负数
        else if (i == length)
        {
            for (int i = 0; i < length; i++)
            {
                nums[i] *= nums[i];
            }
            reverse(nums.begin(), nums.end());
        }
        // 有正又有负
        else
        {
            vector<int> nums1;
            vector<int> nums2;
            for (int j = 0; j < i; j++)
            {
                nums1.push_back(nums[j] * nums[j]);
            }
            reverse(nums1.begin(), nums1.end());
            for (int j = i; j < length; j++)
            {
                nums2.push_back(nums[j] * nums[j]);
            }
            nums.clear();
            int m = 0;
            int n = 0;
            while (m < nums1.size() && n < nums2.size())
            {
                if (nums1[m] <= nums2[n])
                {
                    nums.push_back(nums1[m++]);
                }
                else
                {
                    nums.push_back(nums2[n++]);
                }
            }
            while (m < nums1.size())
            {
                nums.push_back(nums1[m++]);
            }
            while (n < nums2.size())
            {
                nums.push_back(nums2[n++]);
            }
        }
        return nums;
    }
};
// @lc code=end