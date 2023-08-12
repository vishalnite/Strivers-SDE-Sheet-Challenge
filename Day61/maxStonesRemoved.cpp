/*
Find the maximum number of stones that can be removed if the stones should not share row or col with any other stones.
We are given a query of stone nodes.
[Here we need to determine the number of connected components -- Answer would be (Total stones - No. of Components) -- Disjoint Set]
[Find the max row & max col -- number row from 0 to maxrow & col from 0 + maxrow + 1 to maxcol + maxrow + 1]
[Treat each row & col as component -- Connect them if they share a stone]

T.C - O(N)
S.C - O(N)
*/

#include<unordered_map>

class DisjointSet {
    vector<int> rank, parent, size;
    public:
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

int removeStones(vector<vector<int>> &stones){
	int n = stones.size();
    int maxrow = 0;
    int maxcol = 0;
    for(auto it : stones) {
        maxrow = max(it[0], maxrow);
        maxcol = max(it[1], maxcol);
    }

    DisjointSet ds(maxrow + maxcol + 1);
    unordered_map<int, int> stoneNodes;

    for(auto it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxrow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for(auto it : stoneNodes) {
        if(ds.findUParent(it.first) == it.first)
            cnt++;
    }

    return n - cnt;
}
