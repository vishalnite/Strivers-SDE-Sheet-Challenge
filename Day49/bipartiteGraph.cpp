/*
Check if the graph is bipartite. Bipartite graph is a graph in which adjacent nodes can be colored with different colors.
[DFS or BFS]
[BFS -- If the two adjacent node are having same color then it cannot be bipartite]

T.C - O(N + 2E)
S.C - O(2N)
*/

#include<queue>
#include<cstring>

bool check(int start, vector<vector<int>> &adj, int color[]) {
	queue<int> q;
	color[start] = 1;
	q.push(start);

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(auto it : adj[node]) {
			if(color[it] == -1) {
				color[it] = !color[node];
				q.push(it);
			}
			else if(color[it] == color[node]) {
				return false;
			}
		}
	}

	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	int m = edges[0].size();

	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(edges[i][j] == 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int color[n];
	memset(color, -1, sizeof(color));
	
	for(int i = 0; i < n; i++) {
		if(color[i] == -1) {
			if(check(i, adj, color) == false) {
				return false;
			}
		}
	}

	return true;

}