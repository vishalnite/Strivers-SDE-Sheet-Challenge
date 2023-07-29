/*
Detect whether the given undirected graph contains a cycle. The graph can be disconnected.
[BFS or DFS]
[BFS -- If two nodes collide at the same node then it contains a cycle]
[DFS -- If the node has been previously visited other than the parent then it contains a cycle]

T.C - O(N + 2E)
S.C - O(3N)
*/

/* ---------------------------------------------BFS----------------------------------------------- */
#include<queue>

bool detectCycle(int src, vector<vector<int>> &adj, int vis[]) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode : adj[node]) {
            if(!vis[adjacentNode]) {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if(parent != adjacentNode) {
                return true;
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int vis[n + 1] = {0};
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(detectCycle(i, adj, vis))
                return "Yes";
        }
    }

    return "No";

}

/* ---------------------------------------------DFS----------------------------------------------- */

bool detectCycle(int node, int parent, vector<vector<int>> &adj, int vis[]) {
    vis[node] = 1;

    for(auto adjacentNode : adj[node]) {
        if(!vis[adjacentNode]) {
            if(detectCycle(adjacentNode, node, adj, vis) == true)
                return true;
        }
        else if(parent != adjacentNode) {
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int vis[n + 1] = {0};

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(detectCycle(i, -1, adj, vis))
                return "Yes";
        }
    }

    return "No";
}
