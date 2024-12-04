#include<bits/stdc++.h>
using namespace std;

struct edge{
    int y;//表示该边的另一顶点编号
    int distance;//表示该边的距离
};

//表示当前起点到顶点x的最短路径  可随之更新
struct Node{
    int dist;
    int x;
};


bool operator<(Node lhs,Node rhs){
    return lhs.dist>rhs.dist;
}

vector<int> dijkstra(vector<vector<edge>>&graph,int start_point,int &n){
    vector<int>dist(n+1);
    bool isvisit[n+1];
    for(int i=1;i<n+1;i++){
        dist[i]=INT_MAX;
        isvisit[i]=false;
    }
    
    
    priority_queue<Node>pqueue;
    dist[1]=0;
    Node node;
    node.dist=dist[1];
    node.x=1;
    pqueue.push(node);
    while(!pqueue.empty()){
        int x=pqueue.top().x;
        pqueue.pop();
        if(isvisit[x]){
            continue;
        }
        isvisit[x]=true;
        for(int i=0;i<graph[x].size();i++){
            int y=graph[x][i].y;
            int dis=graph[x][i].distance;
            
            if(dist[y]>(dist[x]+dis)){
                dist[y]=dist[x]+dis;
                node.dist=dist[x]+dis;
                node.x=y;
                pqueue.push(node);
            }
            
        }
    }
    return dist;
    
}



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<edge>>graph(n+1);
    //存储图
    for(int i=0;i<m;i++){
        int x,y,distance;
        cin>>x>>y>>distance;
        edge ed;
        ed.y=y;
        ed.distance=distance;
        graph[x].push_back(ed);
        ed.y=x;
        graph[y].push_back(ed);
    }
    vector<int>distance=dijkstra(graph, 1,n);
    int result=0;
    for(long long unsigned int i=1;i<distance.size();i++){
        result+=distance[i];
    }
    cout<<result;
    return 0;
    
    
}