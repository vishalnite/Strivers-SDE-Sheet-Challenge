/*
Find all the possible paths from (0, 0) to (N - 1, N - 1).

T.C - O(4 ^ (N x M))
S.C - O(N x M)
*/

#include <bits/stdc++.h>

void solve(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>> &path, 
vector<vector<int>> &ans, int di[], int dj[]) {
  if(i == n - 1 && j == n - 1) {
    vector<int> temp;
    for(int x = 0; x < n; x++) {
      for(int y = 0; y < n; y++) {
        if(x == n - 1 && y == n - 1)
          temp.push_back(1);
        else
          temp.push_back(path[x][y]);
      }
    }
    ans.push_back(temp);
    return;
  }

  for(int ind = 0; ind < 4; ind++) {
    int nexti = i + di[ind];
    int nextj = j + dj[ind];
    if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !path[nexti][nextj] && maze[nexti][nextj] == 1) {
      path[i][j] = 1;
      solve(nexti, nextj, n, maze, path, ans, di, dj);
      path[i][j] = 0;
    }
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> ans;
  vector<vector<int>> path (n, vector<int>(n, 0));
  int di[] = {+1, 0, 0, -1};
  int dj[] = {0, -1, +1, 0};
  
  if(maze[0][0] == 1)
    solve(0, 0, n, maze, path, ans, di, dj);
  return ans;
}