#include<iostream>
using namespace std;

int n;
int g[20][20];
int vis[20];

void dfs(int u) {
    cout<<u<<" ";
    vis[u]=1;
    for(int v=0;v<n;v++)
        if(g[u][v] && !vis[v])
            dfs(v);
}

int main() {
    int e;
    cout<<"enter vertices and edges: ";
    cin>>n>>e;

    for(int i=0;i<e;i++) {
        int a,b;
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }

    cout<<"dfs order starting from 0: ";
    for(int i=0;i<n;i++) vis[i]=0;
    dfs(0);
}
