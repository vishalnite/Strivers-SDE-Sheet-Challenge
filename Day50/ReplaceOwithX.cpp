/*
Given a matrix containing only 'O' and 'X'. You need to replace 'O' with 'X' in an island, if it is surrounded by 'X'[left, right, up, down].
[DFS or BFS]
[If 'O' is at the boundary them mark all 'O's connected with it as visited i.e, these can't be replaced with 'X']

T.C - O(N * M * 4)
S.C - O(N * M)
*/

#include<vector>

void dfs(int row, int col, vector<vector<int>> &vis, char **arr, int n, int m, int delrow[], 
int delcol[]) {
    vis[row][col] = 1;

    for(int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && arr[nrow][ncol] == 'O') {
            dfs(nrow, ncol, vis, arr, n, m, delrow, delcol);
        }
    }
}

void replaceOWithX(char** arr, int n, int  m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};

    //first and last row
    for(int j = 0; j < m; j++) {
        //first row
        if(arr[0][j] == 'O') {
            dfs(0, j, vis, arr, n, m, delrow, delcol);
        }
        //last row
        if(arr[n - 1][j] == 'O') {
            dfs(n - 1, j, vis, arr, n, m, delrow, delcol);
        }
    }

    //first and last column
    for(int i = 0; i < n; i++) {
        //first column
        if(arr[i][0] == 'O') {
            dfs(i, 0, vis, arr, n, m, delrow, delcol);
        }
        //last column
        if(arr[i][m - 1] == 'O') {
            dfs(i, m - 1, vis, arr, n, m, delrow, delcol);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && arr[i][j] == 'O') {
                arr[i][j] = 'X';
            }
        }
    }

}