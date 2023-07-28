/*
Depth First Search(DFS) in graph.
The graph is not connected. Perform DFS for each component.
[Use resursion to go to depth -- DFS changes with starting node]

T.C - O(N) + O(2E)
S.C - O(3N) ~ O(N)
*/

#include<bits/stdc++.h>

void dfsGraph(vector<vector<int>> &adj, int node, vector<int> &dfs, int vis[]) {
    dfs.push_back(node);
    vis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it]) 
            dfsGraph(adj, it, dfs, vis);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    int n = edges.size();

    for(int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    int vis[V] = {0};

    for(int i = 0; i < V; i++) {
        vector<int> dfs;
        if(!vis[i]) {
            dfsGraph(adj, i, dfs, vis);
            ans.push_back(dfs);
        }
    }

    return ans;
}