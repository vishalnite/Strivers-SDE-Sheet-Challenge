/*
Given a matrixa and a starting coordinate. From that starting node change the values to new values if they are adjacent(4-connectivity).
[use either BFS or  DFS]

T.C - O(N*M)
S.C - O(N*M) + O(N*M) [stack space]
*/

#include<bits/stdc++.h>

void dfs(vector<vector<int>> &image, int x, int y, vector<vector<int>> &ans, int color, 
 int newColor, int delRow[], int delCol[]) {
     ans[x][y] = newColor;
     int n = image.size();
     int m = image[0].size();

     for(int i = 0; i < 4; i++) {
         int nx = x + delRow[i];
         int ny = y + delCol[i];

         if(nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == color && ans[nx][ny] != newColor) {
             dfs(image, nx, ny, ans, color, newColor, delRow, delCol);
         }
     }
 }

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int color = image[x][y];
    vector<vector<int>> ans = image;

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    dfs(image, x, y, ans, color, newColor, delRow, delCol);

    return ans;
}