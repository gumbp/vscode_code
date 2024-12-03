/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        // 按照气球的终点  从小到大排序
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        //至少需要射一次箭 
        int res = 1;
        if (points.size() == 0)
        {
            return 0;
        }
        int end = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                res++;
                end = points[i][1];
            }
        }
        return res;
    }
};
// @lc code=end
