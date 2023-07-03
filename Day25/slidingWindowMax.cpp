/*
Determine the maximum element for each window of size k in a given array.

T.C - O(N) + O(N)
S.C - O(k)
*/

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> dq;
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        while(!dq.empty() && dq.front() == i - k) 
            dq.pop_front();
        
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        if(i >= k - 1) 
            ans.push_back(nums[dq.front()]);
    }

    return ans;
}