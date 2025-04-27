#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Prim 算法实现最小生成树
class PrimMST {
 private:
  int V;                               // 顶点数量
  vector<vector<pair<int, int>>> adj;  // 邻接表表示图：(目标顶点, 权重)

 public:
  PrimMST(int vertices) : V(vertices) { adj.resize(V); }

  // 添加边
  void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});  // 无向图
  }

  // 实现Prim算法
  int primMST() {
    // 存储最小生成树的总权重
    int mstWeight = 0;

    // 使用优先队列(小顶堆)存储边：(权重, 顶点)
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    // 标记顶点是否已包含在MST中
    vector<bool> inMST(V, false);

    // 存储顶点的键值(到MST的最小权重边)
    vector<int> key(V, INT_MAX);

    // 从顶点0开始
    int start = 0;
    pq.push({0, start});
    key[start] = 0;

    // 当所有顶点都加入MST时停止
    while (!pq.empty()) {
      // 获取权重最小的边
      int u = pq.top().second;
      pq.pop();

      // 如果顶点已处理，跳过
      if (inMST[u]) continue;

      // 将顶点加入MST
      inMST[u] = true;
      mstWeight += key[u];

      // 检查所有相邻边
      for (auto& edge : adj[u]) {
        int v = edge.first;        // 邻接顶点
        int weight = edge.second;  // 边权重

        // 如果顶点v不在MST中且权重小于当前key
        if (!inMST[v] && weight < key[v]) {
          // 更新key值
          key[v] = weight;
          // 加入优先队列
          pq.push({key[v], v});
        }
      }
    }

    return mstWeight;
  }

  // 输出MST的边
  void printMST() {
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);  // 存储MST中的父节点

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    int start = 0;
    pq.push({0, start});
    key[start] = 0;

    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      if (inMST[u]) continue;
      inMST[u] = true;

      for (auto& edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;

        if (!inMST[v] && weight < key[v]) {
          parent[v] = u;
          key[v] = weight;
          pq.push({key[v], v});
        }
      }
    }

    cout << "最小生成树的边：\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
      cout << parent[i] << " - " << i << " 权重: " << key[i] << endl;
      totalWeight += key[i];
    }
    cout << "总权重: " << totalWeight << endl;
  }
};

int main() {
  int V = 9;  // 顶点数量
  PrimMST g(V);

  // 添加图的边
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);

  // 计算MST
  int mstWeight = g.primMST();
  cout << "MST的总权重: " << mstWeight << endl;

  // 打印MST
  g.printMST();

  return 0;
}