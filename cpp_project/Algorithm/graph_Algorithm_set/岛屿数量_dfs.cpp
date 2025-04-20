/*
给定一个由 1（陆地）和
0（水）组成的矩阵，你需要计算岛屿的数量。岛屿由水平方向或垂直方向上相邻的陆地连接而成，
并且四周都是水域。你可以假设矩阵外均被水包围。
输入描述：
第一行包含两个整数 N, M，表示矩阵的行数和列数。
后续 N 行，每行包含 M 个数字，数字为 1 或者 0。
输出描述：
输出一个整数，表示岛屿的数量。如果不存在岛屿，则输出 0。
*/

#include <iostream>
#include <vector>
using namespace std;

// 深度搜索优先版
// 遍历矩阵所有节点  标记访问过的节点，同时递归遍历该节点的上下左右方位
void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
  if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1) {
    return;
  }
  grid[i][j] = 2;
  dfs(grid, i - 1, j, rows, cols);
  dfs(grid, i + 1, j, rows, cols);
  dfs(grid, i, j - 1, rows, cols);
  dfs(grid, i, j + 1, rows, cols);
}

int numIslands(vector<vector<int>>& grid) {
  if (grid.empty()) {
    return 0;
  }
  int rows = grid.size();
  int cols = grid[0].size();
  int count = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 1) {
        count++;
        dfs(grid, i, j, rows, cols);
      }
    }
  }
  return count;
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

  cout << numIslands(grid);
  return 0;
}