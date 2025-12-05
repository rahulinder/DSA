#include<iostream>
using namespace std;

int main() {
    int n,e;
    cout<<"enter vertices and edges: ";
    cin>>n>>e;

    int g[20][20]={0};

    cout<<"enter edges (u v w): ";
    for(int i=0;i<e;i++) {
        int a,b,w;
        cin>>a>>b>>w;
        g[a][b]=w;
    }

    int s;
    cout<<"enter source: ";
    cin>>s;

    int d[20], vis[20], parent[20];

    for(int i=0;i<n;i++)
        d[i]=9999, vis[i]=0, parent[i]=-1;

    d[s]=0;

    for(int i=0;i<n;i++) {
        int u=-1;
        for(int v=0;v<n;v++)
            if(!vis[v] && (u==-1 || d[v]<d[u]))
                u=v;

        vis[u]=1;

        for(int v=0;v<n;v++)
            if(g[u][v] && d[u]+g[u][v] < d[v])
                d[v] = d[u] + g[u][v], parent[v]=u;
    }

    cout<<"shortest distances:\n";
    for(int i=0;i<n;i++)
        cout<<"source to "<<i<<" = "<<d[i]<<"\n";
}
