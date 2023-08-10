/*
Find the number of islands for each query. Each query tells us to put a land at that paticular location and then count the number of locations 
at that instant.
[Dynamic array -- Disjoint set application -- DSU on Matrices]

T.C - O(N * M * 4a)
S.C - O(N * M)
*/

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

bool isValid(int row, int col, int n, int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    DisjointSet ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    vector<int> ans;

    int dr[] = {-1, 0, +1, 0};
    int dc[] = {0, -1, 0, +1}; 

    for(int i = 0; i < q; i++) {
        int row = queries[i][0];
        int col = queries[i][1];

        if(vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;
        for(int ind = 0; ind < 4; ind++) {
            int adjr = row + dr[ind];
            int adjc = col + dc[ind];

            if(isValid(adjr, adjc, n, m)) {
                if(vis[adjr][adjc] == 1) {
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;

                    if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)) {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    } 
                }
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}
