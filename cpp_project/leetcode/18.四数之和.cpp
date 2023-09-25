// @before-stub-for-debug-begin
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, long long target)
    {
        if (nums.size() < 4)
        {
            return {};
        }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 3)
        {
            if (nums[i] > target && nums[i] >= 0)
            {
                return res;
            }
            int j = i + 1;
            while (j < nums.size() - 2)
            {
                //确保之后相加的第三第四个数 结果是递增的 
                if (nums[i] + nums[j] > target && nums[j] > 0)
                {
                    break;
                }
                // 定义为长整型，防止计算溢出
                long long temp = target - (nums[i] + nums[j]);
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l)
                {
                    if (nums[k] + nums[l] == temp)
                    {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1])
                            k++;
                        while (k < l && nums[l] == nums[l - 1])
                            l--;
                        k++;
                        l--;
                    }
                    else if (nums[k] + nums[l] < temp)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
                // 对第二个元素降重  防止重复结果
                while (j < (nums.size() - 2) && nums[j] == nums[j + 1])
                    j++;
                j++;
            }
            // 对第一个元素降重  防止重复结果
            while (i < (nums.size() - 3) && nums[i] == nums[i + 1])
                i++;
            i++;
        }
        return res;
    }
};
// @lc code=end