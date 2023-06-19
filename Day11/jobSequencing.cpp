/*
Given jobs with deadlines and profits associated with each job. Determine the maximum profit that can be achieved.

T.C - O(N) + O(NlogN) + O(N * M)
S.C - O(maxDeadline)
*/

#include <bits/stdc++.h> 

bool comparator(vector<int> &a, vector<int> &b) {
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    int maxi = jobs[0][0];
    for(int i = 1; i < n; i++) {
        maxi = max(maxi, jobs[i][0]);
    }

    sort(jobs.begin(), jobs.end(), comparator);

    vector<int> slots (maxi + 1, -1);
    int profits = 0;

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i][0]; j > 0; j--) {
            if(slots[j] == -1) {
                slots[j] = 1;
                profits += jobs[i][1];
                break;
            }
        }
    }

    return profits;
}


