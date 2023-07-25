/*
Count the distinct elements for every window of size K.
[use hashmap and sliding window]

T.C - O(N)
S.C - O(K)
*/

#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{   
    int n = arr.size();
    unordered_map<int, int> mp;
    vector<int> ans;

    for(int i = 0; i < k; i++) {
        mp[arr[i]]++;
    }

    ans.push_back(mp.size());

    for(int i = 0, j = k; j < n; j++, i++) {
        mp[arr[i]]--;
        if(mp[arr[i]] == 0) {
            mp.erase(arr[i]);
        }
        mp[arr[j]]++;
        ans.push_back(mp.size());
    }

    return ans;
}
