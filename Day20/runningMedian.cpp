/* 
Find the median from a data stream. For each incoming data find the current median.

T.C - O(NlogN)
S.C - O(logN)
*/

#include<bits/stdc++.h>

int signum(int a, int b) {
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

void getMedian(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, 
    int val, int &median) {

    switch(signum(maxHeap.size(), minHeap.size())) {
        case 0: if(val > median) {
                    minHeap.push(val);
                    median = minHeap.top(); 
                }
                else {
                    maxHeap.push(val);
                    median = maxHeap.top();
                }
                break;
        case 1: if(val > median) {
                    minHeap.push(val);
                }
                else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(val);
                }
                median = (maxHeap.top() + minHeap.top()) / 2;
                break;
        case -1: if(val > median) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(val);
                }
                else {
                    maxHeap.push(val);
                }
                median = (maxHeap.top() + minHeap.top()) / 2;
    }
}

void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;
    for(int i = 0; i < n; i++) {
        getMedian(maxHeap, minHeap, arr[i], median);
        cout << median << " ";
    }
}