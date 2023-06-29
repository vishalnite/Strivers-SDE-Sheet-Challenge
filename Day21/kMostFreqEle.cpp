/*
Find the K Most frequent elements.

T.C - O(NlogN)
S.C - O(N) + O(N) 
*/

#include <bits/stdc++.h> 

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> mp;
    for(int i : arr)
        mp[i]++;
    
    priority_queue<pair<int, int>> maxHeap;
    for(auto it : mp) {
        maxHeap.push({it.second, it.first});
    }

    vector<int> ans;
    for(int i = 0; i < k; i++) {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}
