/*
Find the shortest path in a directed acyclic graph. The source is given as 0. If we need to find from all nodes then call dfs() for all nodes.
[Using Topological sort]
[Intuition -- The node which is coming first in topological order will have its distance 0 and then it moves to the next node]
[This approach reduces the time complexity]

T.C - O(V + E) + O(N + M)
S.C - O(N + M)
*/

void topoSort(int node, vector<vector<pair<int, int>>> &adj, int vis[], stack<int> &st) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        int v = it.first;
        if(!vis[v]) {
            topoSort(v, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    //create the graph
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    //Perform Topo sort
    int vis[n] = {0};
    stack<int> st;

    topoSort(0, adj, vis, st);

    //Calculate distance
    vector<int> dis(n);
    for(int i = 0; i < n; i++)
        dis[i] = 1e9;

    dis[0] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for(auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if(dis[node] + wt < dis[v]) {
                dis[v] = dis[node] + wt;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(dis[i] == 1e9) {
            dis[i] = -1;
        }
    }

    return dis;
}
