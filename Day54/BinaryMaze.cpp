/*
Given source and destination cells in a binary maze. Find the shortest distance. If there is no path return -1.
[use BFS]

T.C - O(N ^ 2)
S.C - O(N ^ 2)
*/

#include<queue>

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    if(matrix[src.first][src.second] != 1 || matrix[dest.first][dest.second] != 1) {
        return -1;
    }

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src.first, src.second}});
    vis[src.first][src.second] = 1;

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        int pathLen = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if(row == dest.first && col == dest.second) 
            return pathLen;

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == 1 
            && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({pathLen + 1, {nrow, ncol}});
            }
        }
    }

    return -1;
}