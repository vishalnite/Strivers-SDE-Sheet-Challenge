/*
Find the kth largest and smallest element from the array.
[Do not use sorting]

T.C - O(N + K * log(N))
S.C - O(N)
*/

#include<bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int i : arr) {
		maxHeap.push(i);
		minHeap.push(i);
	}

	while(k > 1) {
		maxHeap.pop();
		minHeap.pop();
		k--;
	}

	return {minHeap.top(), maxHeap.top()};
}