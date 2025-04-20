/*
给定一个由 1（陆地）和
0（水）组成的矩阵，岛屿指的是由水平或垂直方向上相邻的陆地单元格组成的区域，且完全被水域单元格包围。孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿。
现在你需要将所有孤岛“沉没”，即将孤岛中的所有陆地单元格（1）转变为水域单元格（0）。
输入描述：
第一行包含两个整数 N, M，表示矩阵的行数和列数。
之后 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。
输出描述
输出将孤岛“沉没”之后的岛屿矩阵。
*/

#include <iostream>
#include <vector>
using namespace std;

// 深度搜索优先版
// 遍历矩阵所有节点  标记访问过的节点，同时递归遍历该节点的上下左右方位
void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
  if (i < 0 || i >= rows || j < 0 || j >= cols) {
    return;
  }
  if (grid[i][j] == 1) {
    grid[i][j] = 2;
    dfs(grid, i - 1, j, rows, cols);
    dfs(grid, i + 1, j, rows, cols);
    dfs(grid, i, j - 1, rows, cols);
    dfs(grid, i, j + 1, rows, cols);
  }
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

  //   将非孤岛陆地标记为2
  for (int i = 0; i < N; i++) {
    if (grid[i][0] == 1) {
      dfs(grid, i, 0, N, M);
    }
    if (grid[i][M - 1] == 1) {
      dfs(grid, i, M - 1, N, M);
    }
  }

  for (int j = 0; j < M; j++) {
    if (grid[0][j] == 1) {
      dfs(grid, 0, j, N, M);
    }
    if (grid[N - 1][j] == 1) {
      dfs(grid, N - 1, j, N, M);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 1) {
        grid[i][j] = 0;
      }
      if (grid[i][j] == 2) {
        grid[i][j] = 1;
      }
    }
    cout << endl;
    for (int j = 0; j < M; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}