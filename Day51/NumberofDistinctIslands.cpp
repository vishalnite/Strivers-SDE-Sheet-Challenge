/*
Find the number of distinct islands(not rotated and refelcted).
[DFS or BFS]
[Store all the islands in a set, which will make sure that unique islands are only inserted]
[Store islands by subtracting each cell by base cell]

T.C - O(N * M) + O(log(N * M)) + O(N * M * 4)
S.C - O(N * M) + O(N * M)
*/

#include<vector>
#include<set>

void dfs(int row, int col, vector<vector<int>> &vis, int **arr, int n, int m, int delrow[],
int delcol[], vector<pair<int, int>> &island, int row0, int col0) {
    vis[row][col] = 1;
    island.push_back({row - row0, col - col0});

    for(int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && arr[nrow][ncol] == 1) {
            dfs(nrow, ncol, vis, arr, n, m, delrow, delcol, island, row0, col0);
        }
    }
}

int distinctIslands(int** arr, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && arr[i][j] == 1) {
                vector<pair<int, int>> island;
                dfs(i, j, vis, arr, n, m, delrow, delcol, island, i, j);
                st.insert(island);
            }
        }
    }    

    return st.size();
}