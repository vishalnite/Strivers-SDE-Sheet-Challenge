/*
Given an n x n grid. Return the size of the largest island which can be obtained by changing at most one cell to 1.
[Graph is changing dynamically -- Disjoint set]

T.C - O(N * N * 4a)
S.C - O(2N)
*/

#include<unordered_set>

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

bool isValid(int row, int col, int n) {
	return row >= 0 && row < n && col >= 0 && col < n;
}

int maximumIslandSize(vector<vector<int>> &grid){
	int n = grid.size();
	DisjointSet ds(n * n);

	int dr[] = {-1, 0, +1, 0};
	int dc[] = {0, -1, 0, +1};

	//Connecting components
	for(int row = 0; row < n; row++) {
		for(int col = 0; col < n; col++) {
			if(grid[row][col] == 0)
				continue;
			
			int nodeNo = row * n + col;
			for(int ind = 0; ind < 4; ind++) {
				int nrow = row + dr[ind];
				int ncol = col + dc[ind];
				int adjNodeNo = nrow * n + ncol;

				if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
					ds.unionBySize(nodeNo, adjNodeNo);
				}
			}
		}
	}

	//Changing each cell to 1 one by one
	int mx = -1;
	for(int row = 0; row < n; row++) {
		for(int col = 0; col < n; col++) {
			if(grid[row][col] == 1)
				continue;

			unordered_set<int> components;
			for(int ind = 0; ind < 4; ind++) {
				int nrow = row + dr[ind];
				int ncol = col + dc[ind];

				if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
					components.insert(ds.findUParent(nrow * n + ncol));
				}
			}

			int sz = 0;
			for(auto it : components) {
				sz += ds.size[it];
			}

			mx = max(mx, sz + 1);
		}
	}

	return mx == -1 ? n * n : mx;
}


