// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem135.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 先满足最小分配
        vector<int> allocate_candy(ratings.size(), 1);
        // 两次for循环遍历
        // 第一层for循环从左往右遍历  确保相邻两个元素中，当较右的大于较左时
        // 较右的分到的糖果能分到多于较左的
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i - 1] < ratings[i])
            {
                allocate_candy[i] = allocate_candy[i - 1] + 1;
            }
        }
        // 第二层for循环从右往左遍历，确保相邻的两个元素中，当左边的元素大于右边的元素时
        // 左边孩子能分到多于右边孩子的糖果
        // 至于判断左边元素是否大于右边元素的比较 为什么要从右往左遍历，那是因为比较时需要
        // 更新allocate_candy[i]的值，这个值的更新依赖于更后面的allocate_candy元素值，如果不是
        // 从右往左遍历，那么allocate_candy的更新就会出错
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                // 这里一开始我犯了了个小错，默认allocate_candy[i+1]+1的值是最大的，其实不然
                // 因为在第一层for循环中，可能存在allocate_candy[i+1]+1并不是最大的
                allocate_candy[i] = max(allocate_candy[i],allocate_candy[i + 1] + 1);
            }
        }
        int res = 0;
        for (auto i : allocate_candy)
        {
            res += i;
        }
        return res;
    }
};
// @lc code=end