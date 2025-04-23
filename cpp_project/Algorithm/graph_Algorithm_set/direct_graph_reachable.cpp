/*
给定一个有向图，包含 N 个节点，节点编号分别为 1，2，...，N。现从 1
号节点开始，如果可以从 1 号节点的边可以到达任何节点，则输出 1，否则输出 -1。
【输入描述】

第一行包含两个正整数，表示节点数量 N 和边的数量 K。 后续 K 行，每行两个正整数 s
和 t，表示从 s 节点有一条边单向连接到 t 节点。

【输出描述】
如果可以从 1 号节点的边可以到达任何节点，则输出 1，否则输出 -1。

*/

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<list<int>>& graph, vector<bool>& visited) {
  queue<int> que;
  visited[1] = true;
  que.push(1);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto i : graph[u]) {
      if (!visited[i]) {
        que.push(i);
        visited[i] = true;
      }
    }
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  //   邻接表存储图
  vector<list<int>> graph(N + 1);
  for (int i = 0; i < K; i++) {
    int s, t;
    cin >> s >> t;
    graph[s].push_back(t);
  }
  vector<bool> visited(N + 1, false);
  bfs(graph, visited);

  if (find(visited.begin() + 1, visited.end(), false) == visited.end()) {
    cout << 1;
  } else {
    cout << -1 << endl;
  }
  cout << endl;
  return 0;
}
