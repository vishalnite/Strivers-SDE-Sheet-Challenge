/*
Check whether the nodes in a graph can be colored with m colors.

T.C - O(N ^ M)
S.C - O(N)
*/

#include <bits/stdc++.h>

bool isSafe(int node, int colors[], vector<vector<int>> &mat, int n, int col) {
    for(int k = 0; k < n; k++) {
        if(k != node && mat[k][node] == 1 && colors[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, int colors[], vector<vector<int>> &mat, int m, int n) {
    if(node == n) {
        return true;
    }

    for(int i = 1; i <= m; i++) {
        if(isSafe(node, colors, mat, n, i)) {
            colors[node] = i;
            if(solve(node + 1, colors, mat, m, n))
                return true;
            colors[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    int colors[n] = {0};
    if(solve(0, colors, mat, m, n))
        return "YES";
    return "NO";
}