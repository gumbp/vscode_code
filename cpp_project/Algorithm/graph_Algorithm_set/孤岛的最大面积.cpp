// 给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿指的是由水平或垂直方向上相邻的陆地单元格组成的区域，
// 且完全被水域单元格包围。孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿。
// 现在你需要计算所有孤岛的总面积，岛屿面积的计算方式为组成岛屿的陆地的总数。
// 输入描述
// 第一行包含两个整数 N, M，表示矩阵的行数和列数。之后 N 行，每行包含 M 个数字，数字为 1 或者 0。
// 输出描述
// 输出一个整数，表示最大孤岛的面积，如果不存在孤岛，则输出 0。


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int area = 0;
int res = 0;

void dfs_change(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
  if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1) {
    return;
  }
  if (grid[i][j] == 0) {
    return;
  }
  grid[i][j] = 0;
  dfs_change(grid, i - 1, j, rows, cols);
  dfs_change(grid, i + 1, j, rows, cols);
  dfs_change(grid, i, j - 1, rows, cols);
  dfs_change(grid, i, j + 1, rows, cols);
}

void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
  if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1) {
    return;
  } else if (grid[i][j] == 0) {
    return;
  }
  grid[i][j] = 2;
  area += 1;
  dfs(grid, i - 1, j, rows, cols);
  dfs(grid, i + 1, j, rows, cols);
  dfs(grid, i, j - 1, rows, cols);
  dfs(grid, i, j + 1, rows, cols);
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> grid;
  grid.resize(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int value;
      cin >> value;
      grid[i].push_back(value);
    }
  }

  for (int j = 0; j < M; j++) {
    if (grid[0][j] == 1) {
      dfs_change(grid, 0, j, N, M);
    }
    if (grid[N - 1][j] == 1) {
      dfs_change(grid, N - 1, j, N, M);
    }
  }
  for (int i = 0; i < N; i++) {
    if (grid[i][0] == 1) {
      dfs_change(grid, i, 0, N, M);
    }
    if (grid[i][M - 1] == 1) {
      dfs_change(grid, i, M - 1, N, M);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 1) {
        res = max(res, area);
        area = 0;
        dfs(grid,i, j, N, M);
      }
    }
  }
  cout << max(res, area);
  return 0;
}