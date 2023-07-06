/*
Find the number of consecutive previous days where the current stock price is greater than previous days.
Calculate span for each day.
[Brute force -- Traverse from current index to prev index and check -- O(N ^ 2)]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> ans;
    stack<int> s;

    s.push(0);
    ans.push_back(1);

    //For each index keep a track of element greater the the current element
    for(int i = 1; i < n; i++) {
        while(!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans.push_back(i + 1);
        }
        else {
            ans.push_back(i - s.top());
        }
        s.push(i);
    }

    return ans;
}