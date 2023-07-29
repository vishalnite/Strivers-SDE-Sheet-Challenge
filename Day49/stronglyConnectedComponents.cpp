/*
Find the strongly connected components.
[Use Kosaraju's algorithm]
1. Sort the graph on the basis of finish time -- Topological sort using DFS
2. Reverse the graph
3. Find the SCC using the stack

T.C - O(3(V + E))
S.C - O(V + E)
*/

#include<bits/stdc++.h>

void dfs(int node, vector<vector<int>> &adj, int vis[], stack<int> &st) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);
}

void dfsSCC(int node, vector<vector<int>> &adj, int vis[], vector<int> &scc) {
    vis[node] = 1;
    scc.push_back(node);

    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfsSCC(it, adj, vis, scc);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    //Adjacency list creation
    vector<vector<int>> adj(n);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //sorting on the basis of finish time
    stack<int> st;
    int vis[n] = {0};

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    //Reversing the graph
    vector<vector<int>> adjT(n);

    for(int i = 0; i < n; i++) {
        vis[i] = 0;
        for(auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    //Finding SCC
    vector<vector<int>> ans;

    while(!st.empty()) {
        vector<int> scc;
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            dfsSCC(node, adjT, vis, scc);
            ans.push_back(scc);
        }
    }

    return ans;

}

