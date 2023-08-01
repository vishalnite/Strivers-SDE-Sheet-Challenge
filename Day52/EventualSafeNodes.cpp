/*
Find the safe nodes whose all paths reach the terminal node.
[All the nodes which are not a part of the cycle]

T.C - O(N) + O(V + E)
S.C - O(3N)
*/

#include <bits/stdc++.h> 

bool dfsCheck(int node, vector<vector<int>> &adj, int vis[], int pathVis[], int check[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfsCheck(it, adj, vis, pathVis, check))
                return true;
        }
        else if(pathVis[it]) {
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    vector<vector<int>> adj(n);

    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    int vis[n] = {0};
    int pathVis[n] = {0};
    int check[n] = {0};

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }

    vector<int> safeNodes;
    for(int i = 0; i < n; i++) {
        if(check[i])
            safeNodes.push_back(i);
    }

    return safeNodes;
}