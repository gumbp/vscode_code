/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> single_res;
    int num = 0;
    void backtracking(vector<int> &candidates, int target, int start_index, int &num)
    {
        if (num == target)
        {
            res.push_back(single_res);
            return;
        }
        else if (num > target)
        {
            return;
        }
        for (int i = start_index; i < candidates.size(); i++)
        {
            if (num + candidates[i] <= target)
            {
                single_res.push_back(candidates[i]);
                num += candidates[i];
                backtracking(candidates, target, i, num); // 本层不是i+1  表示可以重复选择值candidates[i]
                num -= candidates[i];
                single_res.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        if (candidates.size() <= 0)
        {
            return res;
        }
        backtracking(candidates, target, 0, num);
        return res;
    }
};
// @lc code=end