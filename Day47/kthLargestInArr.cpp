/*
Find the kth largest element in an unsorted array.
[use minHeap]

T.C - O(NlogK)
S.C - O(N)
*/

#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int i = 0; i < size; i++) {
		minHeap.push(arr[i]);
		
		if(minHeap.size() > k) {
			minHeap.pop();
		}
	}

	return minHeap.top();
}