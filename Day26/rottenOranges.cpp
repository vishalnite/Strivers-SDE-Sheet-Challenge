/*
Find the time required to rotten all oranges.
[using BFS]

T.C - O(N * M) * 4
S.C - O(N * M)
*/

#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int cntFresh = 0;
    vector<vector<int>> oranges(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    // {{r, c}, t}

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != 0) {
                oranges[i][j] = grid[i][j];

                if(grid[i][j] == 1) {
                    cntFresh++;
                }
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
    }

    int cnt = 0, time = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        
        time = max(time, t);
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < n && nc < m && nr >= 0 && nc >= 0 && oranges[nr][nc] == 1) {
                q.push({{nr, nc}, t + 1});
                oranges[nr][nc] = 2;
                cnt++;
            }
        }
    }

    if(cnt != cntFresh)
        return -1;
    return time;
}