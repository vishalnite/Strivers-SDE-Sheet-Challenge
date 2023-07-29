/*
Given a matrix where each cell contains either 0(water) or 1(land). The task is to find the number of islands.
[It can be thought as a disconnected graph]
[When we find the starting node then we can apply any traversal algorithm to find the connected nodes]
[The number of starting node gives the number of islands]

T.C - O(N^2 * 8)
S.C - O(N^2) + O(N^2)
*/

#include<queue>

void bfs(int row, int col, vector<vector<int>> &vis, int **arr, int n, int m) {
   vis[row][col] = 1;
   queue<pair<int, int>> q;
   q.push({row, col});

   while(!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      for(int delRow = -1; delRow <= 1; delRow++) {
         for(int delCol = -1; delCol <= 1; delCol++) {
            int nrow = r + delRow;
            int ncol = c + delCol;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && arr[nrow][ncol] == 1) {
               q.push({nrow, ncol});
               vis[nrow][ncol] = 1;
            }
         }
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{  
   int cnt = 0;
   vector<vector<int>> vis(n, vector<int>(m, 0));
   
   for(int row = 0; row < n; row++) {
      for(int col = 0; col < m; col++) {
         if(!vis[row][col] && arr[row][col] == 1) {
            cnt++;
            bfs(row, col, vis, arr, n, m);
         }
      }
   }

   return cnt;
}
