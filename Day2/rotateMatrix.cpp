/*
Rotate the matrix clockwise.
Hint - Do spiral traversal of the matrix.

T.C - O(N * M)
S.C - O(1)
*/

#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    while(top < bottom && left < right) { //change from normal spiral traversal - while(top <= bottom && left <= right)
        int r = top, c = left;
        int prev = mat[top][left], curr = mat[top][left];

        for(int i = left + 1; i <= right; i++) {
            curr = mat[top][i];
            mat[top][i] = prev;
            prev = curr;
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            curr = mat[i][right];
            mat[i][right] = prev;
            prev = curr;
        }
        right--;

        if(top <= bottom) {
          for (int i = right; i >= left; i--) {
            curr = mat[bottom][i];
            mat[bottom][i] = prev;
            prev = curr;
          }
          bottom--;
        }
        
        if(left <= right) {
          for (int i = bottom; i >= top; i--) {
            curr = mat[i][left];
            mat[i][left] = prev;
            prev = curr;
          }
          left++;
        }
        
        mat[r][c] = prev;
    }

}