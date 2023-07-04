/*
Implement min stack.
[This can be done on O(2N) space complexity by storing a pair in stack -- pair's second element is the smallest element until that point]
[Optimal approach uses O(N) space complexity -- Modify the element value if it is less than min value -- push & pop affected]

T.C - O(1)
S.C - O(N)
*/

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	stack<long long> st;
	long long mini;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			mini = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			long long val = num;
			if(st.empty()) {
				st.push(val);
				mini = val;
			}
			else {
				if(val < mini) {
					st.push(2 * val * 1LL - mini);
					mini = val;
				}
				else {
					st.push(val);
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty()) return -1;

			long long val = st.top();
			st.pop();
			long long ans = val;

			if(val < mini) {
				ans = mini;
				mini = 2 * mini * 1LL - val;
			}

			return ans;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty()) return -1;

			long long val = st.top();
			if(val < mini) 
				return mini;
			return val;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(st.empty()) return -1;
			
			return mini;
		}
};