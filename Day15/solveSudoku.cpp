/*
Given a 9x9 sudoku. Solve the given sudoku.

T.C - O(9 ^ (N ^ 2))
S.C - O(1)
*/

#include<bits/stdc++.h>

bool isValid(int row, int col, int matrix[9][9], int k) {
    for(int i = 0; i < 9; i++) {
        if(matrix[i][col] == k) 
            return false;
        if(matrix[row][i] == k)
            return false;
        if(matrix[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == k) 
            return false;
    }
    return true;
}

bool solve(int matrix[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(matrix[i][j] == 0) {
                for(int k = 1; k <= 9; k++) {
                    if(isValid(i, j, matrix, k)) {
                        matrix[i][j] = k;

                        if(solve(matrix))
                            return true;
                        else    
                            matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    solve(matrix);
}
