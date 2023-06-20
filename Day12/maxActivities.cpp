/*
FInd the maximum number of activities that can be performed by a person if start and finish time of N activities are given.

T.C - O(N) + O(NlogN) + O(N) = O(NlogN)
S.C - O(N)
*/

#include<bits/stdc++.h>

struct activity {
    int start;
    int end;
};

bool static comparator(activity a, activity b) {
    if(a.end < b.end) return true;
    else if(a.end > b.end) return false;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &end) {
    int n = start.size();
    activity A[n];

    for(int i = 0; i < n; i++) {
        A[i].start = start[i];
        A[i].end = end[i];
    }

    sort(A, A + n, comparator);

    int count = 1;
    int lim = A[0].end;

    for(int i = 1; i < n; i++) {
        if(A[i].start >= lim) {
            count++;
            lim = A[i].end;
        }
    }

    return count;
}