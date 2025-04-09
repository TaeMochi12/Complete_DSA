#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=6;
    int src=0;

    // works for negative weight edges too
    vector<vector<int>> edges={{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}};

    vector<int> dist(n,1e8);
    dist[src]=0;

    // n-1 relaxations
    for(int i=0;i<n-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            if(dist[u]!=1e8 && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }

    // nth relaxation for detecting negative cycles
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            // if a negative cycle exists do the needful
            if(dist[u]!=1e8 && dist[u]+wt<dist[v])
            {
                return {-1};
            }
        }

        for(auto it:dist)
        {
            cout<<it<<endl;
        }

}