// #include<iostream>
// using namespace std;
// const int N = 1010;
// int f[N];
// int v[N],w[N];
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i = 1 ; i <= n ;i ++)
//     {
//         cin>>v[i]>>w[i];
//     }

//     for(int i = 1 ; i<=n ;i++){
//     for(int j = v[i] ; j<=m ;j++)
//     {
//             f[j] = max(f[j],f[j-v[i]]+w[i]);
//     }
//     cout<<f[m]<<endl;
//     }
// }


#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int N,V;
    cin>>N>>V;
    const int a=1024;
    const int b=1024;
    int type_weight[N+1];
    int weight[N+1];
    for(int i=1;i<=N;i++){
        cin>>type_weight[i]>>weight[i];
    }
    
    int value[a][b]={0};
    for(int i=1;i<=N;i++){
        for(int j=1;j<=V;j++){
            for(int k=0;k*weight[i]<=j;k++){

                value[i][j]=max(value[i][j],value[i-1][j-k*type_weight[i]]+k*weight[i]);
            }
        }   
            
    }
    cout<<value[N][V];
    // return 0;
    
}