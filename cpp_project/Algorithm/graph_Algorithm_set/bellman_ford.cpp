#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid;
  for (int i = 0; i < m; i++) {
    int start, end, weight;
    cin >> start >> end >> weight;
    grid.push_back({start, end, weight});
  }

  vector<int> miniDist(n + 1, INT_MAX);
  vector<int> prev(n + 1, -1); // 前驱数组，用于记录路径
  miniDist[1] = 0;

  // Bellman-Ford主循环
  for (int i = 1; i < n; i++) {
    for (auto &edge : grid) {
      int from = edge[0];
      int to = edge[1];
      int weight = edge[2];
      if (miniDist[from] != INT_MAX && miniDist[from] + weight < miniDist[to]) {
        miniDist[to] = miniDist[from] + weight;
        prev[to] = from; // 记录前驱节点
      }
    }
  }

  // 检测负权环
  for (auto &edge : grid) {
    int from = edge[0];
    int to = edge[1];
    int weight = edge[2];
    if (miniDist[from] != INT_MAX && miniDist[from] + weight < miniDist[to]) {
      cout << "Graph contains a negative weight cycle" << endl;
      return 0;
    }
  }

  // 输出最短距离
  if (miniDist[n] == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << "Shortest distance to node " << n << ": " << miniDist[n] << endl;

    // 还原路径
    vector<int> path;
    for (int at = n; at != -1; at = prev[at]) {
      path.push_back(at);
    }
    reverse(path.begin(), path.end());

    // 输出路径
    cout << "Path: ";
    for (int node : path) {
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}