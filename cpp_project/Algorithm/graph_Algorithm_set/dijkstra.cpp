#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 300
// 实现单源最短路径
// 定义某一顶点所关联的边的的信息
struct Edge {
  int y;       // 该边的另一顶点编号
  int weight;  // 该边权重
};
// 表示起点到顶点x的最短距离
struct Node {
  int dist;
  int x;
};

vector<Edge> graph[300];  // 定义该图 以邻接表的形式
// 重载<运算符，便于计算调整小根堆（优先级队列）
bool operator<(Node lhs, Node rhs) { return lhs.dist > rhs.dist; }
// s为起点  t为终点
int dijksdra(int s, int t, int n) {
  int dist[N];  // 记录起点到各点的最短距离，初始时为无穷大
                // 例如dist[i]表示起点到顶点i的最短距离
  bool isvisit[N];
  if (s < 0 || t > (n - 1)) {
    cout << "起点或终点错误，请重新输入";
    return -1;
  }
  for (int i = 0; i < n; i++) {
    dist[i] = INT_MAX;  // 初值为无穷大
    isvisit[i] = false;
  }
  priority_queue<Node>
      pqueue;  // 第一次访问到某个节点的时候 再把它加入到优先队列
  // 第一个入队的结点显然为起点s
  dist[s] = 0;
  Node node;
  node.dist = dist[s];
  node.x = s;
  pqueue.push(node);
  while (pqueue.empty() == false) {
    int x = pqueue.top().x;  // x表示当前小根堆中距离最小的路径的顶点右编号
    pqueue.pop();
    if (isvisit[x] == true) {
      continue;
    }
    isvisit[x] = true;
    for (int i = 0; i < graph[x].size();
         i++) {  // 遍历顶点x关联的且未被访问过的边，并挑选符合条件的
      int y = graph[x][i].y;
      int weight = graph[x][i].weight;
      // 如果起点到y的距离大于先到x再到y的距离 则更新到顶点y的最短路径长度
      if (dist[y] > dist[x] + weight) {
        dist[y] = dist[x] + weight;
        node.dist = dist[y];
        node.x = y;
        pqueue.push(node);
      }
    }
  }
  if (dist[t] != INT_MAX)  // 表示起点到终点可达,则返回所求的最短距离
  {
    cout << "该最短路径存在,"
         << "从顶点" << s << "到顶点" << t << "的最短距离为：" << endl;
    return dist[t];
  }
  cout << "该点不可达" << endl;
  return -1;
}

int main() {
  int n, m;  // n表示顶点数 m表示边数
  cout << "请输入顶点数和边数" << endl;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    graph[i].clear();  // 清理残留的边
  }
  cout << "请输入顶点编号及边的权重" << endl;
  for (int i = 0; i < m; ++i) {
    int x, y, weight;  // 边的左顶点、右顶点编号  及边的权重
    cin >> x >> y >> weight;
    Edge edge;
    // 将该边信息录入
    edge.y = y;
    edge.weight = weight;
    // 此时将该边的信息读入图中
    graph[x].push_back(edge);
    // 该图为无向图  随即更新另一起点的边的信息
    edge.y = x;
    graph[y].push_back(edge);
  }

  cout << "无向图的信息为：" << endl;
  cout << "左顶点   "
       << "右顶点   "
       << "权重" << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < graph[i].size();
         j++) {  // graph[i][j]表示以顶点i为起点的第（j+1）条边
      cout << i << "   " << graph[i][j].y << "   " << graph[i][j].weight
           << endl;
    }
  }
  char instruction;
  do {
    int s, t;  // 起点，终点信息
    cout << "请输入起点及终点编号" << endl;
    cin >> s >> t;
    cout << dijksdra(s, t, n) << endl;
    cout << "是否继续输入？（Y/N）";
    cin >> instruction;
  } while (instruction == 'Y' || instruction == 'y');
  return 0;
}