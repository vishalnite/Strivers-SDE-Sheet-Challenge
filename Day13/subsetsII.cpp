/*
Find all the subsets from the given list. The subsets should not be duplicates.
[Recursion -- Don't pick duplicates -- maintain a data structure -- At each recursion generate a list of particular size]

T.C - O(2^N * k) 
S.C - O(2^N * k) -- Avg. length of subset = k
Auxiliary space of recursion - O(N)
*/

#include <bits/stdc++.h> 

void findSubsets(int idx, vector<int> &arr, int n, vector<int> &ds, vector<vector<int>> &ans) {
    ans.push_back(ds);
    for(int i = idx; i < n; i++) {
        if(i != idx && arr[i] == arr[i - 1]) continue;
        ds.push_back(arr[i]);
        findSubsets(i + 1, arr, n, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    findSubsets(0, arr, n, ds, ans);
    return ans;
}