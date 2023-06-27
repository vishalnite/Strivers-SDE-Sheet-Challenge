/*
Implement min heap.

T.C - [insertion & deletion] - O(logN)
*/

#include <bits/stdc++.h> 

void deleteFromHeap(vector<int> &minHeap, vector<int> &ans) {
    if(minHeap.size() == 0) 
        return;

    ans.push_back(minHeap[0]);
    minHeap[0] = minHeap.back();
    minHeap.pop_back();
    int n = minHeap.size();

    int ind = 0;
    while(ind < n) {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int swap_ind = ind;

        if(left < n && minHeap[left] < minHeap[ind]) {
            swap_ind = left;
        }
        if(right < n && minHeap[right] < minHeap[swap_ind]) {
            swap_ind = right;
        }
        
        if(swap_ind != ind) {
            swap(minHeap[ind], minHeap[swap_ind]);
            ind = swap_ind;
        }
        else {
            return;
        }
    }
}

void insertIntoHeap(vector<int> &minHeap, int val) {
    minHeap.push_back(val);
    int ind = minHeap.size() - 1;

    while(ind > 0) {
        int parent = (ind - 1) / 2;
        if (minHeap[parent] > minHeap[ind]) {
          swap(minHeap[parent], minHeap[ind]);
          ind = parent;
        }
        else 
            return;
    }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> minHeap;
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(q[i][0] == 0) {
            insertIntoHeap(minHeap, q[i][1]);
        }
        else {
            deleteFromHeap(minHeap, ans);
        }
    }

    return ans;
}
