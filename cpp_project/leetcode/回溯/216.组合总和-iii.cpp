/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtrace(int &k, int &n, int startIndex, int sum)
    {
        if (sum == n && path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9;i++){
            path.push_back(i);
            sum += i;
            backtrace(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrace(k, n, 1, 0);
        return res;
    }
};
// @lc code=end
