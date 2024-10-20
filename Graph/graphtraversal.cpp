#include<bits/stdc++.h>
using namespace std ;

void dfs(int start,vector<int>adj[],vector<int>&visited)
{
    visited[start]=1;
    cout<<start<<endl;
    for(auto it:adj[start])
    {
        if(!visited[it]) dfs(it,adj,visited);
    }
}

void bfs(int start, vector<int>adj[],vector<int>&visited)
{
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        cout<<front<<endl;
        for(auto it:adj[front])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it]=1;
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(n);
    // cout<<"DFS:"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     if(!visited[i]) dfs(i,adj,visited);
    // }
    cout<<"BFS:"<<endl;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]) bfs(i,adj,visited);
    }
    return 0 ;
}