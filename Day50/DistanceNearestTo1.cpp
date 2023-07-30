/*
Find the distance of nearest 1 from a cell given a binary matrix.
[Use BFS]
[Put all the cells having 1 with initial step as 0 -- Increment step with each level call]

T.C - O(N * M * 4)
S.C - O(N * M)
*/

#include<queue>

vector<vector<int>> nearest(vector<vector<int>> &mat, int n, int m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dis[row][col] = steps;

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }

    return dis;
}