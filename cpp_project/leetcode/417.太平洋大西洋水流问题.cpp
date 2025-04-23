/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
// @lc code=start
class Solution {
 public:
  void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int row,
           int col, int i, int j) {
    visited[i][j] = true;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int k = 0; k < 4; k++) {
      int next_x = i + dx[k];
      int next_y = j + dy[k];

      if (next_x < 0 || next_x >= row || next_y < 0 || next_y >= col ||
          visited[next_x][next_y]) {
        continue;
      }

      // 只有当相邻单元格高度 >= 当前单元格高度时，水才能从相邻单元格流到当前单元格
      if (heights[next_x][next_y] >= heights[i][j]) {
        dfs(heights, visited, row, col, next_x, next_y);
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    if (heights.empty()) return {};

    int row = heights.size();
    int col = heights[0].size();

    vector<vector<bool>> pacific(row, vector<bool>(col, false));
    vector<vector<bool>> atlantic(row, vector<bool>(col, false));

    // 太平洋：左边界和上边界
    for (int i = 0; i < row; i++) dfs(heights, pacific, row, col, i, 0);
    for (int j = 0; j < col; j++) dfs(heights, pacific, row, col, 0, j);

    // 大西洋：右边界和下边界
    for (int i = 0; i < row; i++) dfs(heights, atlantic, row, col, i, col - 1);
    for (int j = 0; j < col; j++) dfs(heights, atlantic, row, col, row - 1, j);

    vector<vector<int>> result;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }
};
// @lc code=end