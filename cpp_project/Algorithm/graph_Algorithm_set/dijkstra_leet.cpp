#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<list<pair<int, int>>> graph(N + 1);
  for (int i = 0; i < M; i++) {
    int s, e, v;
    cin >> s >> e >> v;

    // s->e边的权重为v
    graph[s].push_back({v, e});
  }
  //   队列中的元素为{到该点的距离，该点编号}
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;
  int start = 1;
  vector<bool> isvisited(N + 1, false);
  vector<int> minDst(N + 1, INT_MAX);
  que.push({0, 1});
  minDst[start] = 0;
  while (!que.empty()) {
    pair<int, int> cur = que.top();
    que.pop();

    int curDist = cur.first;   // 当前距离
    int curNode = cur.second;  // 当前节点

    if (isvisited[curNode]) {
      continue;
    }
    isvisited[curNode] = true;

    for (auto &edge : graph[curNode]) {
      int weight = edge.first;     // 边的权重
      int nextNode = edge.second;  // 目标节点

      if (minDst[nextNode] > curDist + weight) {
        minDst[nextNode] = curDist + weight;
        que.push({minDst[nextNode], nextNode});
      }
    }
  }
  if (minDst[N] == INT_MAX) {
    cout << -1;
    return 0;
  }
  cout << minDst[N] << endl;
  return 0;
}
