#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*
    0 -> {}
    1 -> {}
    2 -> {3}
    3 -> {1}
    4 -> {0,1}
    5 -> {0,2}
    */
   int v,n;
   cout<<"Enter no. of vertices:";
   cin>>v;
   cout<<"Enter no. of edges:";
   cin>>n;
   vector<vector<int>> adj(v);
   cout<<"Enter the edges:"<<endl;
   for(int i=0;i<n;i++)
   {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);  
   }
   vector<int>indegree(n,0);
   for(int i=0;i<n;i++)
   {
    for(auto it:adj[i])
    {
        indegree[it]++;
    }
   }
   queue<int> q;
   vector<int> ans;

   for(int i=0;i<n;i++)
   {
    if(indegree[i]==0) q.push(i);
   }

   while(!q.empty())
   {
    int node=q.front();
    q.pop();
    ans.push_back(node);
    for(auto it: adj[node])
    {
        indegree[it]--;
        if(indegree[it]==0) q.push(it);
    }
   }

   cout<<"Topo Sort:"<<endl;
   for(auto it:ans)
   {
    cout<<it<<endl;
   }
   return 0;

}

// TC : O(V+E)
// SC : O(N)