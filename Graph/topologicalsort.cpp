#include<bits/stdc++.h>
using namespace std;
void dfs_topologicalSort(int node,vector<int> &visited,vector<vector<int>> &adj,stack<int> &st)
{
    visited[node]=1;
    for(int it:adj[node])
    {
        if(!visited[it]) dfs_topologicalSort(it,visited,adj,st);
    }
    st.push(node);
}

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
   vector<int>visited(n,0);
   stack<int> st;
   for(int i=0;i<n;i++)
   {
    if(!visited[i]) dfs_topologicalSort(i,visited,adj,st);
   }
   cout<<"Topological Sort:"<<endl;
   while(!st.empty())
   {
    cout<<st.top()<<" ";
    st.pop();
   }
   return 0;

}