/*
Find the number of trap cells. A trap cell is a cell from which we cannot move out of the matrix.
[DFS or BFS]
[Mark all the cells which are reachable from the boundary -- count the number of cells remaining]

T.C - O(N * M * 4)
S.C - O(N * M)
*/

int matrixTraps(int N,int M,vector<vector<int>> &Matrix)
{
    vector<vector<int>> vis(N, vector<int>(M, 0));
    queue<pair<int, int>> q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == 0 || j == 0 || i == N - 1 || j == M - 1) {
                if(Matrix[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < N - 1 && ncol >= 0 && ncol < M - 1 && !vis[nrow][ncol] 
                && Matrix[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
        }
    }

    int traps = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M;  j++) {
            if(vis[i][j] == 0 && Matrix[i][j] == 0) {
                traps++;
            }
        }
    }

    return traps;
}