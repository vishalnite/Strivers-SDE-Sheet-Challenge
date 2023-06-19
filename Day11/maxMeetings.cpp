/*
Return the meetings that can happen if there is only one meeting room.

T.C - O(N) + O(NlogN) + O(N) = O(NlogN)
S.C - O(N)
*/

#include <bits/stdc++.h> 

struct meet {
    int start;
    int end;
    int pos;
};

bool static comparator(meet m1, meet m2) {
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if (m1.pos < m2.pos) return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    meet m[n];
    for(int i = 0; i < n; i++) {
        m[i].start = start[i];
        m[i].end = end[i];
        m[i].pos = i + 1;
    }

    sort(m, m + n, comparator);

    vector<int> ans;
    ans.push_back(m[0].pos);
    int lim = m[0].end;

    for(int i = 1; i < n; i++) {
        if(m[i].start > lim) {
            ans.push_back(m[i].pos);
            lim = m[i].end;
        }
    }

    return ans;
}