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
// #include <pair>
#include <queue>
using namespace std;
void bfs(vector<vector<int>>& grid, int& num) {
  queue<pair<int, int>> my_que;
  if (grid.size() == 0) {
    return;
  }
  int row = grid.size();
  int col = grid[0].size();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      // 若当前陆地未访问 则加1
      if (grid[i][j] == 1) {
        num++;
        grid[i][j] = 2;
        my_que.push({i, j});
        while (!my_que.empty()) {
          pair<int, int> current_node = my_que.front();
          my_que.pop();
          if (current_node.first - 1 >= 0 &&
              grid[current_node.first - 1][current_node.second] == 1) {
            grid[current_node.first - 1][current_node.second] = 2;
            my_que.push({current_node.first - 1, current_node.second});
          }
          if (current_node.first + 1 < row &&
              grid[current_node.first + 1][current_node.second] == 1) {
            grid[current_node.first + 1][current_node.second] = 2;
            my_que.push({current_node.first + 1, current_node.second});
          }
          if (current_node.second - 1 >= 0 &&
              grid[current_node.first][current_node.second - 1] == 1) {
            grid[current_node.first][current_node.second - 1] = 2;
            my_que.push({current_node.first, current_node.second - 1});
          }
          if (current_node.second + 1 < col &&
              grid[current_node.first][current_node.second + 1] == 1) {
            grid[current_node.first][current_node.second + 1] = 2;
            my_que.push({current_node.first, current_node.second + 1});
          }
        }
      }
    }
  }
}

int num_Islands(vector<vector<int>>& grid) {
  int num = 0;
  bfs(grid, num);
  return num;
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
  cout << num_Islands(grid) << endl;
  return 0;
}