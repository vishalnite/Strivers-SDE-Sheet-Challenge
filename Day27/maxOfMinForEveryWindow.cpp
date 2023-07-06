/*
The problem is to find maximin value from the minmum of every window size.
[Brute forece -- Do as the problem suggest -- very easy -- O(N ^ 3)]
[Optimal solution -- Reverse engineering -- find left smaller & right smaller for each element & compute the length for which
 the element could be a possible max value -- O(N)]
 [Dry run to understand better]

T.C - O(N) + O(N) + O(N)
S.C - O(2N)
*/

#include <bits/stdc++.h> 

vector<int> findLeftSmaller(vector<int> &a, int n) {
    vector<int> leftSmaller(n, -1);
    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && a[i] <= a[s.top()]) {
            s.pop();
        }

        if(!s.empty()) {
            leftSmaller[i] = s.top();
        }

        s.push(i);
    }

    return leftSmaller;
}

vector<int> findRightSmaller(vector<int> &a, int n) {
    vector<int> rightSmaller(n, n);
    stack<int> s;
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && a[i] <= a[s.top()]) {
            s.pop();
        }

        if(!s.empty()) {
            rightSmaller[i] = s.top();
        }

        s.push(i);
    }
    return rightSmaller;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans(n, INT_MIN);
    vector<int> leftSmaller = findLeftSmaller(a, n);
    vector<int> rightSmaller = findRightSmaller(a, n);

    for(int i = 0; i < n; i++) {
        int length = rightSmaller[i] - leftSmaller[i] - 1;
        ans[length - 1] = max(a[i], ans[length - 1]);
    }

    for(int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}
