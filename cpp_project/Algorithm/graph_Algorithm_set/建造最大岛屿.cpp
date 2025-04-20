/*
给定一个由 1（陆地）和
0（水）组成的矩阵，你最多可以将矩阵中的一格水变为一块陆地，在执行了此操作之后，矩阵中最大的岛屿面积是多少。
岛屿面积的计算方式为组成岛屿的陆地的总数。岛屿是被水包围，并且通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设矩阵外均被水包围。
输入描述：
第一行包含两个整数 N, M，表示矩阵的行数和列数。之后 N 行，每行包含 M
个数字，数字为 1 或者 0，表示岛屿的单元格。 输出描述：
输出一个整数，表示最大的岛屿面积。
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dict = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int max_area = 0;

void dfs(vector<vector<int>> &grid, int i, int j, int &current_area) {
  int N = grid.size();
  int M = grid[0].size();

  if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] == 0) {
    return;
  } else if (grid[i][j] == 1) {
    current_area++;
    grid[i][j] = 2;
    for (int k = 0; k < 4; k++) {
      int next_x = i + dict[k][0];
      int next_y = j + dict[k][1];
      dfs(grid, next_x, next_y, current_area);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> grid;
  grid.resize(N);
  int current_area = 0;
  // 输入该矩阵
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int value;
      cin >> value;
      grid[i].push_back(value);
    }
  }

  vector<vector<int>> grid_back_up = grid;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        // 暴力算法  遇到为0时，将该块地置为1，从该块地遍历计算可能得到的最大面积并更新
        // 结束时将地图数组复原
      if (grid[i][j] == 0) {
        grid[i][j] = 1;
        dfs(grid, i, j, current_area);
        max_area = max(max_area, current_area);
        current_area = 0;
        grid = grid_back_up;
      }
    }
  }
  cout << max_area;
  return 0;
}