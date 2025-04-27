/*
 * @Author: Mr.Gan
 * @Date: 2025-04-25 16:04:22
 * @Last Modified by:   Mr.Gan
 * @Last Modified time: 2025-04-25 16:04:22
 */
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  size_t N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N);
  vector<int> inDegree(N, 0);
  vector<int> res;
  queue<int> que;
  for (size_t i = 0; i < M; i++) {
    int s, t;
    cin >> s >> t;
    graph[s].push_back(t);
    inDegree[t]++;
  }

  for (size_t i = 0; i < inDegree.size(); i++) {
    if (inDegree[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    size_t vertex = que.front();
    que.pop();
    res.push_back(vertex);
    for (size_t i = 0; i < graph[vertex].size(); i++) {
      inDegree[graph[vertex][i]]--;
      if (inDegree[graph[vertex][i]] == 0) {
        que.push(graph[vertex][i]);
      }
    }
  }

  if (res.size() != N) {
    cout << -1;
    return 0;
  }

  for (const auto &it : res) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}