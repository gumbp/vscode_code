/*
【题目描述】
给定一个有 n 个节点的有向无环图，节点编号从 1 到
n。请编写一个程序，找出并返回所有从节点 1 到节点 n
的路径。每条路径应以节点编号的列表形式表示。 【输入描述】 第一行包含两个整数
N，M，表示图中拥有 N 个节点，M 条边 后续 M 行，每行包含两个整数 s 和
t，表示图中的 s 节点与 t 节点中有一条路径 【输出描述】
输出所有的可达路径，路径中所有节点的后面跟一个空格，每条路径独占一行，
存在多条路径，路径输出的顺序可任意。
如果不存在任何一条路径，则输出 -1。
注意输出的序列中，最后一个节点后面没有空格！ 例如正确的答案是 1 3 5,而不是 1 3 5
，5后面没有空格！
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> all_route;

// 定义图的数据结构
// 边集数组表示的图
struct Graph {
  int V;
  vector<vector<int>> adj;  // 邻接表存储的图
};

void Traverse_path(Graph &graph, vector<int> &route, vector<bool> &visit,
                   int start_index) {
  route.push_back(start_index);
  if (route.back() == graph.V) {
    all_route.push_back(route);
    route.pop_back();
    return;
  }
  visit[start_index] = true;
  //   for循环遍历当前节点的所有邻接节点
  for (int i = 0; i < graph.adj[start_index].size(); i++) {
    if (!visit[graph.adj[start_index][i]]) {
      Traverse_path(graph, route, visit, graph.adj[start_index][i]);
    }
}
// 回溯,经过当前节点start_index到终点的所有路径已经找过，现移除路径中的当前节点，
// 找另一条不经过当前节点的路径
  route.pop_back();
  visit[start_index] = false;
}

int main() {
  int N, M;
  cin >> N >> M;
  Graph graph;
  graph.V = N;
  graph.adj.resize(N + 1);  // 节点从1开始编号
  vector<int> route;
  vector<bool> visit(N + 1, false);

  for (int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    graph.adj[start].push_back(end);
  }
  int start_point = 1;
  Traverse_path(graph, route, visit, start_point);
  if (all_route.size() == 0) {
    cout << "-1";
    return 0;
  }

  for (auto &path : all_route) {
    for (auto &node : path) {
      cout << node << " ";
    }
    cout << endl;
  }
  return 0;
}
