#include <iostream>
#include <vector>
using namespace std;

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
};

int main() {
  int N;
  int s, t;
  cin >> N;
  UFS ufs(N + 1);
  while (N--) {
    cin >> s >> t;
    if (ufs.isSame(s, t)) {
      cout << s << " " << t;
      return 0;
    }
    ufs.join(s, t);
  }
  return 0;
}