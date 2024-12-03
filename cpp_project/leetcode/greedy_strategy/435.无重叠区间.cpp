/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
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
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int remove_count = 0;
        // 记录区间分割点
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            // 若当前区间不重叠 更新end的值 用于下一次判断
            if (end <= intervals[i][0])
            {
                end = intervals[i][1];
            }
            // 当前区间与上一个区间有重叠
            // 则移除当前区间与上一个区间中  末端较长的那个
            else
            {
                end = min(end, intervals[i][1]);
                remove_count++;
            }
        }
        return remove_count;
    }
};
// @lc code=end
