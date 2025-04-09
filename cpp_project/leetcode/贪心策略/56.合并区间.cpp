/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i - 1][1] < intervals[i][0])
            {
                res.push_back(intervals[i - 1]);
            }
            else
            {
                intervals[i][0] = min(start, intervals[i][0]);
                intervals[i][1] = max(end, intervals[i][1]);
            }
            // 更新当前区间的首尾值
            start = intervals[i][0];
            end = intervals[i][1];
        }
        if (res.size() == 0 || res[res.size() - 1][1] < intervals[intervals.size() - 1][1])
        {
            res.push_back(intervals[intervals.size() - 1]);
        }
        return res;
    }
};
// @lc code=end