// @before-stub-for-debug-begin
#include "commoncppproblem1005.h"
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
    // 重写排序的比较逻辑，绝对值大的数排前面
    static bool cmp(int &a, int &b)
    {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        // while(k--){
        //     int x = pq.top();
        //     pq.pop();
        //     pq.push(x * -1);
        // }
        // int res = 0;
        // while(!pq.empty()){
        //     res += pq.top();
        //     pq.pop();
        // }
        // return res;

        // 另一种方法
        // 局部最优：让绝对值大的负数变为正数，当前数值达到最大，整体最优：整个数组和达到最大，
        // 局部最优推出全局最优
        // 还有个问题，如果将全部负数转变为正数了，k仍大于0，那么只需将最小的数反反复复转变，此时数组和达到了最大
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k % 2 == 1)
        {
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        }
        int res = 0;
        for (auto i : nums)
        {
            res += i;
        }
        return res;
    }
};
// @lc code=end