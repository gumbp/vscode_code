/*
 * @Author: Mr.Gan 
 * @Date: 2024-04-22 21:42:34 
 * @Last Modified by:   Mr.Gan 
 * @Last Modified time: 2024-04-22 21:42:34 
 */
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
// @lc code=start
class Solution
{
public:
    // 记录结果
    vector<vector<string>> res;
    void backtracking(int n, vector<string> &chessboard, int row)
    {

        if (row == n)
        {
            res.push_back(chessboard);
            return;
        }
        // for循环遍历当前行的每一个位置  查找当前行中符合条件的每一个位置
        for (int cow = 0; cow < n; cow++)
        {
            if (isValid(row, cow, chessboard, n))
            {
                // 确定当前行的某个位置可放置Q
                chessboard[row][cow] = 'Q';
                // 递归进入下一行 搜索下一个可放置的位置
                backtracking(n, chessboard, row + 1);
                // 回溯  将满足条件的当前行的某列置回默认值 for循环遍历查找当前行的下一个满足条件的位置
                chessboard[row][cow] = '.';
            }
        }
    }

    // 判断该位置是否适合放置Q
    // 根据题意 Q不能在同一行 或同一列 或对角线上
    bool isValid(int &row, int &cow, vector<string> &chessboard, int &n)
    {
        // 由于递归是从第一行逐步向下进行的 因此避免了同一行中重复放置‘Q’的问题
        // 判断同一列上是否已经有了‘Q’
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][cow] == 'Q')
            {
                return false;
            }
        }
        // 判断chessboard[row][cow]位置的正对角线上，之前是否存在过‘Q’
        for (int i = row - 1, j = cow - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        // 判断chessboard[row][cow]位置的逆对角线上，之前是否存在过‘Q’
        for (int i = row - 1, j = cow + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        // 创建n*n大小的且默认值为‘.’的棋盘
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, chessboard, 0);
        return res;
    }
};
// @lc code=end
