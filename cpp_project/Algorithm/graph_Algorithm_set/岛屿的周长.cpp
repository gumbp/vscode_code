/*
给定一个由 1（陆地）和
0（水）组成的矩阵，岛屿是被水包围，并且通过水平方向或垂直方向上相邻的陆地连接而成的。
你可以假设矩阵外均被水包围。在矩阵中恰好拥有一个岛屿，假设组成岛屿的陆地边长都为
1，请计算岛屿的周长。岛屿内部没有水域。 输入描述 第一行包含两个整数 N,
M，表示矩阵的行数和列数。之后 N 行，每行包含 M 个数字，数字为 1 或者
0，表示岛屿的单元格。 输出描述 输出一个整数，表示岛屿的周长。
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dict = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int num = 0;

void judge_adjacent(vector<vector<int>> &grid, int i, int j, int &count) {
  int N = grid.size();
  int M = grid[0].size();
  for (int k = 0; k < 4; k++) {
    int next_i = i + dict[k][0];
    int next_j = j + dict[k][1];
    if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < M &&
        grid[next_i][next_j] == 2) {
      count--;
    }
  }
}

void dfs(vector<vector<int>> &grid, int i, int j, int &N, int &M) {
  if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != 1) {
    return;
  }
  num++;
  grid[i][j] = 2;
  for (int k = 0; k < 4; k++) {
    int next_i = i + dict[k][0];
    int next_j = j + dict[k][1];
    dfs(grid, next_i, next_j, N, M);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> grid;
  bool flag = true;
  int total_size;
  grid.resize(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int value;
      cin >> value;
      grid[i].push_back(value);
    }
  }
  for (int i = 0; i < N && flag; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 1) {
        dfs(grid, i, j, N, M);
        flag = false;
        break;
      }
    }
  }
  total_size = num * 4;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 2) {
        judge_adjacent(grid, i, j, total_size);
      }
    }
  }
  cout << total_size;
  return 0;
}