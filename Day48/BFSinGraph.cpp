/*
Breadth First Search(BFS) in a graph.
Here, the connected nodes should be put in sorted order and also the graph is disconnected.
[First create adjacency list, if not already given -- maintain a queue to store neighboring nodes -- Finally store the remaining nodes(disconnected)]

T.C - O(3N) ~ O(N)
S.C - O(N) + O(2E) ~ O(2E)
*/

#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    int n = edges.size();
    vector<vector<int>> adj(vertex);

    for(int i = 0; i < n; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for(int i = 0; i < vertex; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> bfs;
    queue<int> q;
    int vis[vertex] = {0};

    q.push(0);
    vis[0] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        bfs.push_back(node);
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    for(int i = 0; i < vertex; i++){
        if(vis[i]==0) 
            bfs.push_back(i);
    }

    return bfs;

}