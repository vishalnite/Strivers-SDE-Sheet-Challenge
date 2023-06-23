/*
Find all the board configurations to keep N queens such that none of then attack each other.

T.C - O(N! * N)
S.C - O(N)
*/

// bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
//     int dupcol = col;
//     int duprow = row;

//     while(row >= 0 && col >= 0) {
//         if(board[row][col] == 1) return false;
//         col--;
//         row--;
//     }

//     col = dupcol;
//     row = duprow;
//     while(col >= 0) {
//         if(board[row][col] == 1) return false;
//         col--;
//     }

//     col = dupcol;
//     while(row < n && col >= 0) {
//         if(board[row][col] == 1) return false;
//         row++;
//         col--;
//     }

//     return true;
// }

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n, vector<int> &leftRow, 
vector<int> &lowerDiagonal, vector<int> &upperDiagonal) {
    if(col == n) {
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }

    for(int row = 0; row < n; row++) {
      if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
        board[row][col] = 1;
        leftRow[row] = 1;
        lowerDiagonal[row + col] = 1;
        upperDiagonal[n - 1 + col - row] = 1;
        solve(col + 1, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
        board[row][col] = 0;
        leftRow[row] = 0;
        lowerDiagonal[row + col] = 0;
        upperDiagonal[n - 1 + col - row] = 0;
      }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<int> row(n, 0);
    vector<vector<int>> board;
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        board.push_back(row);
    }
    vector<int> leftRow(n, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    solve(0, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
    return ans;
}