/*
Strongly connected component - where each node can reach to other nodes
Find the number of SCC.
[use Kosaraju's algorithm]
[Sort the graph in terms of finishing time]
[Reverse all the edges]
[Do DFS traversal]

T.C - O(3(V + E))
S.C - O(V + E)
*/

#include<stack>
#include<unordered_map>

void topoSort(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
	vis[node] = 1;

	for(auto adjNode : adj[node]) {
		if(!vis[adjNode]) {
			topoSort(adjNode, adj, vis, st);
		}
	}

	st.push(node);
}

void dfs(int node, vector<vector<int>> &graph, vector<int> &vis) {
	vis[node] = 1;

	for(auto adjNode : graph[node]) {
		if(!vis[adjNode]) {
			dfs(adjNode, graph, vis);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	vector<vector<int>> adj(v), graph(v);
	for(auto it : edges) {
		int u = it[0];
		int v = it[1];
		adj[u].push_back(v);
		graph[v].push_back(u);
	}

	stack<int> st;
	vector<int> vis(v, 0);

	for(int i = 0; i < v; i++) {
		if(!vis[i])
			topoSort(i, adj, vis, st);
	}

	for(int i = 0; i < v; i++) 
		vis[i] = 0;

	int cnt = 0;
	while(!st.empty()) {
		int node = st.top();
		if(!vis[node]) {
			cnt++;
			dfs(node, graph, vis);
		}
		st.pop();
	}

	return cnt;	
}