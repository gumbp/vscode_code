#include <iostream>
#include <vector>
using namespace std;

class UFS {
 private:
  int n;  // 节点数量
  vector<int> father;

 public:
  UFS(int size) : n(size) {
    father.resize(n);
    init();
  }

  //  并查集初始化
  void init() {
    for (int i = 1; i <= n; i++) {
      father[i] = i;
    }
  }
  // 并查集里寻根过程 同时压缩路径 降低查找的时间开销
  int find(int &u) { return u == father[u] ? u : father[u] = find(father[u]); }

  //   判断u和v是否找到一个根
  bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
  }

  //   将v->u这条边加入并查集
  void join(int &u, int &v) {
    u = find(u);
    v = find(v);
    // 若u==v 则说明原先uv在同一个集合 直接返回
    if (u == v) {
      return;
    }
    father[v] = u;
  }

  bool isTreeAfterRemove(const vector<vector<int>> &edge, int deleteEdge) {
    for (int i = 0; i < n; i++) {
      // continue表示忽略这条以deletedge开头的边 也即删除
      // 忽略之后通过并查集判断剩余的边是否仍是联通的
      if (i == deleteEdge) continue;
      // 如果构成了环 删除这条边后一定不是树
      if (isSame(edge[i][0], edge[i][1])) {
        return false;
      }
      join(edge[i][0], edge[i][1]);
    }
    return true;
  }

  void getRemoveEdge(vector<vector<int>> edge) {
    for (int i = 0; i < n; i++) {
      if (isSame(edge[i][0], edge[i][1])) {
        cout << edge[i][0] << " " << edge[i][1];
        return;
      } else {
        join(edge[i][0], edge[i][1]);
      }
    }
  }
};

int main() {
  int N;
  int s, t;
  cin >> N;
  UFS ufs(N + 1);
  vector<vector<int>> edges;
  vector<int> inDegree(N + 1, 0);
  while (N--) {
    cin >> s >> t;
    inDegree[t]++;
    edges.push_back({s, t});
  }
  vector<int> vec;  // recording the point where inDegree is 2
  for (int i = N - 1; i >= 0; i--) {
    if (inDegree[edges[i][1]] == 2) {
      vec.push_back(i);
    }
  }

  // 如果存在入度为2的顶点 ，区分是情况1还是情况2
  if (vec.size()) {
    if (ufs.isTreeAfterRemove(edges, vec[0])) {
      cout << edges[vec[0]][0] << " " << edges[vec[0]][1];
    } else {
      cout << edges[vec[1]][0] << " " << edges[vec[1]][1];
    }
    return 0;
  }
  ufs.getRemoveEdge(edges);
  return 0;
}
