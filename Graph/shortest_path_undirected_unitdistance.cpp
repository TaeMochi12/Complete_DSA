#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N = 9, M = 11;
  
  vector<vector<int>> edges= {{0,1},{0,3},{1,3},{1,2},{2,6},{3,4},{4,5},{5,6},{6,7},{6,8},{7,8}};
  vector<vector<int>> adj(N); // or vector<int> adj[N]
  for(auto it:edges)
  {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  int src;
  cout<<"Enter source node:";
  cin>>src;
  vector<int>dist(N,1e9);
  dist[src]=0;
  queue<int> q;
  q.push(src);
  while(!q.empty())
  {
    int node=q.front();
    q.pop();

    for(int it:adj[node])
    {
        if(dist[node]+1<dist[it])
        {
            // Update distance and push in the queue
            dist[it]=dist[node]+1;
            q.push(it);
        }
    }
  }
  for(int i=0;i<N;i++)
  {
    cout<<i<<":"<<dist[i]<<endl;
  }
  return 0;

}

// TC : O(N+M)
// SC : O(N+M) for storing all the edges in adjacency list