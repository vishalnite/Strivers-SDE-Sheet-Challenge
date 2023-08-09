/*
Given a number of disconnected graphs. Find the minimum number of operations required to make them connected.
Use Disjoint Set to find the extra edges (bcoz disjoint set stores only n - 1 edges) and the number of components (Checking ultimate boss)
The number of real edges(not imaginary) required to connect N components will be N - 1

T.C - O(M * 4a)
S.C - O(2N)
*/

#include<bits/stdc++.h>

class DisjointSet {
    public:
		vector<int> rank, parent, size;

        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for(int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUParent(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v)
                return;
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v)
                return;
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v]; 
            }
        }
};

int makeGraphConnected(int n, vector<pair<int, int>>edges, int m) 
{
	DisjointSet ds(n);
	int extraEdges = 0;
	int cntConnected = 0;

	for(int i = 0; i < m; i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		if(ds.findUParent(u) == ds.findUParent(v)) {
			extraEdges++;
		}
		else {
			ds.unionByRank(u, v);
		}
	} 

	for(int i = 1; i <= n; i++) {
		if(ds.parent[i] == i) {
			cntConnected++;
		}
	}

	int ans = cntConnected - 1;

	if(extraEdges >= ans)
		return ans;
	return -1;
}