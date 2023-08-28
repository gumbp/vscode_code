/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> a(n, vector<int>(n));
        int num = 1;
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        while (num <= n * n)
        {
            // 从左到右
            for (int i = left; i <= right; i++)
            {
                a[top][i] = num++;
            }
            top++;
            //从上到下
            for (int i = top; i <= bottom; i++)
            {
                a[i][right] = num++;
            }
            right--;
            //从右到左
            for (int i = right; i >= left; i--)
            {
                a[bottom][i] = num++;
            }
            bottom--;
            //从下到上
            for (int i = bottom; i >= top; i--)
            {
                a[i][left] = num++;
            }
            left++;
        }
        return a;
    }
};

// @lc code=end