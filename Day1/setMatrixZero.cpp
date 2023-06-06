/* 
Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

Brute force: T.C - O(N * M * (N + M))   S.C - O(1)
Better: T.C - O(N * M)  S.C - O(N + M)
Optimal: T.C - O(N * M) S.C - O(1)
*/

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	// vector<int> rows(n, 0); -- matrix[..][0]
	// vector<int> cols(m, 0); -- matrix[0][..]
	int col0 = 1; // for handling overlapping of 1st element

	for(int i = 0; i < n; i++) { //marking first row and first column
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 0) {
				matrix[i][0] = 0;

				if(j != 0) //To avoid marking matrix[0][0] again
					matrix[0][j] = 0;
				else
					col0 = 0;
			}
		}
	}

	//Changing the matrix values - leave the first row and first column
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}

	//First check matrix[0][0] to avoid conflict in first row
	if(matrix[0][0] == 0) {
		for(int j = 0; j < m; j++) 
			matrix[0][j] = 0;
	}

	//Change first column now
	if(col0 == 0) {
		for(int i = 0; i < n; i++)
			matrix[i][0] = 0;
	}

}