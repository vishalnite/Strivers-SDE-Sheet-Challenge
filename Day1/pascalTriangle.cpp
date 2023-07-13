/*
Generate Pascal's triangle.
T.C - O(N * N)
S.C - O(1)
*/

#include<bits/stdc++.h>

vector<int> generateRow(int row) {
        vector<int> ansRow;
        ansRow.push_back(1); //First element of each row is 1
        long long res = 1;
        //With each next element we are multiplying it with (row - col)/(col)
        //Dry run with an example to understand it better
        for(int col = 1; col < row; col++) { 
            res = res * (row - col);
            res = res / col;
            ansRow.push_back(res);
        }
        return ansRow;
    }    

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    //Generatind each row of pascal triangle
    for(int i = 1; i <= numRows; i++) {
        ans.push_back(generateRow(i));
    }

    return ans;
}