#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 并查集实现
class UFS {
 private:
  int n;  // 节点数量
  vector<int> father;

 public:
  UFS(int size) : n(size) {
    father.resize(size);
    init();
  }

  //  并查集初始化
  void init() {
    for (int i = 1; i <= n; i++) {
      father[i] = i;
    }
  }
  // 并查集里寻根过程 同时压缩路径 降低查找的时间开销
  int find(int u) { return u == father[u] ? u : father[u] = find(father[u]); }

  //   判断u和v是否找到一个根
  bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
  }

  //   将v->u这条边加入并查集
  void join(int u, int v) {
    u = find(u);
    v = find(v);
    // 若u==v 则说明原先uv在同一个集合 直接返回
    if (u == v) {
      return;
    }
    father[v] = u;
  }
};

struct Edge {
  int start, end, weight;
  /* data */
};

int main() {
  int V, E;
  cin >> V >> E;
  UFS ufs(V + 1);

  vector<Edge> graph;
  Edge edge;
  for (int i = 0; i < E; i++) {
    cintopological >> edge.start >> edge.end >> edge.weight;
    graph.push_back(edge);
  }
  sort(graph.begin(), graph.end(),
       [](const Edge &a, const Edge &b) { return a.weight < b.weight; });

  int min_mst = 0;
  cout << "最小生成树的边为:" << endl;
  for (const auto &edge : graph) {
    int x = ufs.find(edge.start);
    int y = ufs.find(edge.end);
    if (x != y) {
      ufs.join(x, y);
      min_mst += edge.weight;
      cout << edge.start << "----" << edge.end;
      cout << endl;
    }
  }
  cout << "mst_weight=" << min_mst;
  return 0;
}
