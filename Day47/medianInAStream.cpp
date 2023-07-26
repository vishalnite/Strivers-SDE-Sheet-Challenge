/*
Find median in a running stream.
[Use maxHeap and minHeap -- maxHeap will be greater in size then minHeap -- change accordingly]

T.C - O(NlogN)
S.C - O(N)
*/

#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int x : arr) {
		if(maxHeap.size() == minHeap.size()) {
			if(maxHeap.size() == 0 || x <= minHeap.top()) {
				maxHeap.push(x);
			}
			else {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(x);
			}

			ans.push_back(maxHeap.top());
		}
		else {
			if(x < maxHeap.top()) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(x);
			}
			else {
				minHeap.push(x);
			}

			ans.push_back((maxHeap.top() + minHeap.top()) / 2);
		}
	}

	return ans;

}
