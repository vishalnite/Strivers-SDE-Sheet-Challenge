/*
Find the next greater element at the right side of each element in the array.
[It may ask for circular arrays -- Update index as i % n]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    
    vector<int> ans(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        
        while(!st.empty() && arr[i] >= st.top()) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }
        
        st.push(arr[i]);
    }

    return ans;
}