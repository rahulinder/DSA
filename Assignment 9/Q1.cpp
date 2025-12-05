#include<iostream>
using namespace std;

int main() {
    int n,e;
    cout<<"enter number of vertices and edges: ";
    cin>>n>>e;

    int g[20][20]={0};

    cout<<"enter edges (u v): ";
    for(int i=0;i<e;i++) {
        int a,b;
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }

    cout<<"graph built. starting bfs from 0\n";

    int vis[20]={0};
    int q[20], f=0, r=0;

    int s=0;
    q[r++]=s;
    vis[s]=1;

    cout<<"bfs order: ";
    while(f<r) {
        int u=q[f++];
        cout<<u<<" ";
        for(int v=0;v<n;v++)
            if(g[u][v]==1 && !vis[v])
                vis[v]=1, q[r++]=v;
    }
}
