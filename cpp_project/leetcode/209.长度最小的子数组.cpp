/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        else if (find(nums.begin(), nums.end(), target) != nums.end())
        {
            return 1;
        }
        int ans = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= target)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end