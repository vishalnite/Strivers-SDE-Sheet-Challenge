/*
Find the number of provinces. Given a roads matrix, if roads[i][j] = 1 then there is a road between city i and j.
[Number of provinces mean the number of components in a graph]
[DFS or BFS]
[Here we are given an adjacency matrix -- we can either convert it into adjacency list or do it directly]

T.C - O(N) + O(V + 2E)
S.C - O(N)
*/

void dfs(int node, int vis[], vector<vector<int>>& roads, int n) {
    vis[node] = 1;

    for(int i = 0; i < n; i++) {
        if(!vis[i] && roads[node][i] == 1) {
            dfs(i, vis, roads, n);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    
    int provincesCnt = 0;
    int vis[n] = {0};

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            provincesCnt++;
            dfs(i, vis, roads, n);
        }
    }

    return provincesCnt;

}