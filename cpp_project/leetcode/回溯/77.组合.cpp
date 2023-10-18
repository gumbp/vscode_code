// @before-stub-for-debug-begin
#include "commoncppproblem77.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracting(int &n, int &k, int startIndex)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
//剪枝优化
//n-i:当前未遍历过的剩余的元素个数
//k-path.size():组合数中仍需要的元素个数
//只有当剩余的元素个数大于等于组合数仍需要的个数  本层for循环才有进行的意义 否则可直接跳过
//即：n-i>=k-path.size()  加1是因为包括起始位置 我们需要的是一个左闭区间

        for (int i = startIndex; i <= n-(k-path.size())+1; i++)
        // for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            backtracting(n, k, i + 1);
            //执行到这一步表示backtrace函数已经返回 存储了一个正确的组合  需弹出该组合数的最后一个数  保留前k-1个数的序列进行下一次遍历
            path.pop_back(); // 回溯  弹出处理过的点
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backtracting(n, k, 1);
        return res;
    }
};
// @lc code=end
