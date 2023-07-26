/*
Find the kth largest element in a data stram.
[Use minHeap]

T.C - O(N*logK)
S.C - O(N)
*/

#include <algorithm>

class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;

    Kthlargest(int k, vector<int> &arr) {
        for(int i = 0; i < k; i++) {
            minHeap.push(arr[i]);
        }
    }

    int add(int num) {
        minHeap.push(num);
        minHeap.pop();

        return minHeap.top();
    }

};