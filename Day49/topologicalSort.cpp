/*
Topological sort of a graph using DFS.
[While returning from the DFS call store it in a stack]
[stack contains the topological sort]

T.C - O(N + E)
S.C - O(2N)
*/

#include <bits/stdc++.h> 

void dfs(int node, vector<vector<int>> &adj, int vis[], stack<int> &st) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it])
            dfs(it, adj, vis, st);
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> ans;
    stack<int> st;
    int vis[v] = {0};

    for(int i = 0; i < v; i++) {
        if(!vis[i])
            dfs(i, adj, vis, st);
    }
    
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}