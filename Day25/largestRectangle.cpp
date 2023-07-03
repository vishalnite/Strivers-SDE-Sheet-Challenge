/*
Find the largest rectangle that can be formed from the given histogram.
[Brute -- O(N^2)]
[Better -- Remember next greater and next smaler element problem and put the elements in stack in increasing order -- O(N) + O(N) + O(N) + O(N)]
[Optimal -- In a single pass compute the result  -- A bit complex to explain -- May not be required if not asked -- O(N) + O(N)]
*/

//Better Solution

 #include<bits/stdc++.h>
 
 int largestRectangle(vector<int> &heights) {
   
    int n = heights.size();
    vector<int> leftSmaller(n, 0), rightSmaller(n, n - 1);
    stack<int> st;

    for(int i = 0; i < n; i++) {
      while(!st.empty() && heights[st.top()] >= heights[i]) {
        st.pop();
      }

      if(!st.empty()) {
        leftSmaller[i] = st.top() + 1;
      }

      st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n - 1; i >= 0; i--) {
      while(!st.empty() && heights[st.top()] >= heights[i]) {
        st.pop();
      }

      if(!st.empty()) {
        rightSmaller[i] = st.top() - 1;
      }

      st.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      ans = max(ans, (rightSmaller[i] - leftSmaller[i] + 1) * heights[i]);
    }   

    return ans;
 }

 //Optimal SOlution
  #include<bits/stdc++.h>
 
 int largestRectangle(vector<int> &heights) {
   
    int n = heights.size();
    stack<int> s;
    int maxA = 0;

    for(int i = 0; i <= n; i++) {
      while(!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
        int height = heights[s.top()];
        s.pop();
        int width;
        if(s.empty())
          width = i;
        else
          width = i - s.top() - 1;
        maxA = max(maxA, height * width);
      }

      s.push(i);
    }

    return maxA;
 }