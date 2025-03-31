#include<bits/stdc++.h>
using namespace std ;
int main() {
    int n,m;
    cin>>n>>m;

    // if graph is 0 based then make adjacency of n size
    // in case of directed graphs we won't insert the vice-versa edges:
    // adj[v][u]=1;
    // adj_list[v].push_back(u);

    // Adjacency matrix - TC : O(n) SC : O(n^2)
    int adj[n+1][n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    // Adjacency List - TC : O(n) SC : O(2*m(no. of edges))
    // For directed - SC : O(m)
    vector<int>adj_list[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }


// ======================= FOR WEIGHTED GRAPHS ========================

int adj_mat[n+1][n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u][v]=wt;
        adj[v][u]=wt;
    }

vector<pair<int,int>>adj_list[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj_list[u].push_back({v,wt});
        adj_list[v].push_back({u,wt});
    }


    return 0 ;
}