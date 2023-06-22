/*
Return subset with sum K. Each element can be picked once.

T.C - O(2^N)
S.C - O(2^N)
*/

void findSubsets(int idx, int sum, vector<int> &arr, int n, int k, vector<int> &ds, vector<vector<int>> &ans) {
    if(idx == n) {
        if(sum == k) 
            ans.push_back(ds);
        return;
    }

    ds.push_back(arr[idx]);
    findSubsets(idx + 1, sum + arr[idx], arr, n, k, ds, ans);
    ds.pop_back();
    findSubsets(idx + 1, sum, arr, n, k, ds, ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findSubsets(0, 0, arr, n, k, ds, ans);
    return ans;
}