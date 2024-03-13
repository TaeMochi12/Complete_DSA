#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int u, v;
    int wt;

    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt;
}

// Find the parent of a set using path compression
int findPar(int u, vector<int> &parent) {
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

// Union two sets using union by rank
void union_sets(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        if (rank[u] == rank[v]) {
            rank[u]++;
        }
    }
}

int main() {
    int n, m;
    // Input the number of vertices and edges
    cin >> n >> m;
    vector<node> edges;

    // Input the edges: source vertex, destination vertex, and weight
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    // Initialize the parent array for disjoint set union
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    // Initialize the rank array for union by rank
    vector<int> rank(n, 0);

    // Sort the edges based on weight
    // n long n e log v -> m log n + 
    // n log n
    sort(edges.begin(), edges.end(), comp);

    int cost = 0;
    vector<pair<int, int>> mst;

    // Kruskal's algorithm to find minimum spanning tree
    for (auto it : edges) {
        if (findPar(it.v, parent) != findPar(it.u, parent)) {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            union_sets(it.u, it.v, parent, rank);
        }
    }
    // Output the total cost of the minimum spanning tree
    cout << "Total cost of the minimum spanning tree: " << cost << endl;
    // Output the edges in the minimum spanning tree
    cout << "Edges in the minimum spanning tree:" << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;

    return 0;
    
   // O(m log m)
 }
