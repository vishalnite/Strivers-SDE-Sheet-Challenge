/*
Find the celebrity in a party. If not present return -1.
A celebrity is one who does-not know anyone but is known by everyone.
[Brute force -- O(N^2) -- Check for each person]
[Optimal -- stack -- The last element left can be a potential celebrity -- verify at the end]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> s;
	for(int i = 0; i < n; i++) {
		s.push(i);
	}

	while(s.size() > 1) {
		int a = s.top();
		s.pop();
		int b = s.top();
		s.pop();

		if(knows(a, b)) {
			s.push(b);
		}
		else {
			s.push(a);
		}
	}

	int id = s.top();

	for(int i = 0; i < n; i++) {
		if(i == id) continue;
		if(knows(id, i) || !knows(i, id)) 
			return -1;
	}

	return id;
}