/*
Merge k sorted arrays.

T.C - O((N*K)*log(K))
S.C - O(K)
*/

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
    vector<int> ans;

    for(int i = 0; i < k; i++) {
        pq.push({kArrays[i][0], {i, 0}});
    }

    while(pq.size() > 0) {
        auto p = pq.top();
        pq.pop();
        int val = p.first;
        int li = p.second.first;
        int di = p.second.second;

        ans.push_back(val);

        if(di + 1 < kArrays[li].size()) {
            pq.push({kArrays[li][di + 1], {li, di + 1}});
        }
    }

    return ans;
}
