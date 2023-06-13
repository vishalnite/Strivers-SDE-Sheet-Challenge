/*
Find the lenght of the longest subsequence.

T.C - O(N) + O(2N)
S.C - O(N)
*/

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(auto num : arr) {
        st.insert(num);
    }

    for(auto it : st) {
        if(st.find(it - 1) == st.end()) {
            int count = 1;
            int x = it;
            while(st.find(x + 1) != st.end()) {
                count++;
                x = x + 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}