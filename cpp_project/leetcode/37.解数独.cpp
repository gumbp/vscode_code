/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
// @lc code=start
class Solution
{
public:
    //传递row参数  避免冗余遍历
    bool backtracking(vector<vector<char>> &board,int row)
    {
        for (int i = row; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <='9'; k++)
                    {
                        if (isValid(board, i, j, k))
                        {
                            board[i][j] = k;
                            if (backtracking(board,i))
                            {
                                return true;
                            }
                            // 回溯
                            board[i][j] = '.';
                        }
                    }
                    // 在该位置中   9个数都试完且无法满足条件  则返回false  表示在之前的填写方案下 到该位置后是无解的
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int &row, int &col, char &value)
    {
        // 判断同一列是否存在相同的值
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][col] == value)
            {
                return false;
            }
        }
        // 判断同一行是否存在相同的值
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[row][j] == value)
            {
                return false;
            }
        }

        // 判断粗实线分隔的3*3方格内是否出现过该值
        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;
        for (int i = startrow; i < startrow + 3; i++)
        {
            for (int j = startcol; j < startcol + 3; j++)
            {
                if (board[i][j] == value)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board,0);
    }
};
// @lc code=end
