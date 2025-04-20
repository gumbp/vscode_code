/*
现有一个 N × M 的矩阵，每个单元格包含一个数值，这个数值代表该位置的相对高度。
矩阵的左边界和上边界被认为是第一组边界，而矩阵的右边界和下边界被视为第二组边界。
矩阵模拟了一个地形，当雨水落在上面时，水会根据地形的倾斜向低处流动，
但只能从较高或等高的地点流向较低或等高并且相邻（上下左右方向）的地点。
我们的目标是确定那些单元格，从这些单元格出发的水可以达到第一组边界和第二组边界。
输入描述：
第一行包含两个整数 N 和 M，分别表示矩阵的行数和列数。
后续 N 行，每行包含 M 个整数，表示矩阵中的每个单元格的高度。

输出描述:
输出共有多行，每行输出两个整数，用一个空格隔开，
表示可达第一组边界和第二组边界的单元格的坐标，输出顺序任意。
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dict{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(vector<vector<int>> const &grid, int i, int j, int &N, int &M,
         vector<vector<bool>> &visited) {
  if (visited[i][j]) {
    return;
  }
  visited[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int next_i = i + dict[k][0];
    int next_j = j + dict[k][1];
    if (next_i < 0 || next_i >= N || next_j < 0 || next_j > M ||
        grid[i][j] > grid[next_i][next_j]) {
      continue;
    }
    dfs(grid, next_i, next_j, N, M, visited);
  }
  return;
}
// 表明触碰到了边界

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> pacific(N, vector<bool>(M, false));
  vector<vector<bool>> atlantic(N, vector<bool>(M, false));
  vector<vector<int>> grid;
  //   vector<vector<int>> res;
  grid.resize(N);
  vector<pair<int, int>> res;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int value;
      cin >> value;
      grid[i].push_back(value);
    }
  }

  for (int i = 0; i < N; i++) {
    dfs(grid, i, 0, N, M, pacific);
    dfs(grid, i, M - 1, N, M, atlantic);
  }
  for (int j = 0; j < M; j++) {
    dfs(grid, 0, j, N, M, pacific);
    dfs(grid, N - 1, j, N, M, atlantic);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (pacific[i][j] && atlantic[i][j]) {
        res.push_back({i, j});
      }
    }
  }

  for (auto &it : res) {
    cout << it.first << " " << it.second;
    cout << endl;
  }
  return 0;
}