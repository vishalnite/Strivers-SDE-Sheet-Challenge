/*
Find the cycle in a directed graph.
[Same algorithm as undirected will not work here because the cycle formed should be on the same path]
[DFS -- maintain two arrays vis[] and pathVis[] -- If both of them are 1 then there is a cycle]

T.C - O(N + 2E)
S.C - O(2N) [can be done in O(N) -- maintain a single vis[] -- mark 2 for every path visited]
*/

bool detectCycle(int node, vector<vector<int>> &adj, int vis[], int pathVis[]) {
  vis[node] = 1;
  pathVis[node] = 1;

  for(auto adjacentNode : adj[node]) {
    if(!vis[adjacentNode]) {
      if(detectCycle(adjacentNode, adj, vis, pathVis))
        return true;
    }
    else if(pathVis[adjacentNode]) {
      return true;
    }
  }

  pathVis[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {

  vector<vector<int>> adj(n + 1);

  for(int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  int vis[n + 1] = {0};
  int pathVis[n + 1] = {0};

  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      if(detectCycle(i, adj, vis, pathVis))
        return 1;
    }
  }

  return 0;

}