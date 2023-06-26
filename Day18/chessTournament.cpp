/*
In a chess tournament the players should stay in rooms with maximum distance between them. 
Find the minimum of the maximum between players.

T.C - O(NlogN)
S.C - O(1)
*/

#include <bits/stdc++.h>

bool isPossible(vector<int> &positions, int n, int players, int dist) {
	int placed = 1;
	int lastPosition = positions[0];
	for(int i = 1; i < n; i++) {
		if(positions[i] - lastPosition >= dist) {
			placed++;
			lastPosition = positions[i];
		}
		if(placed == players)
			return true;
	}
	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());

	int low = 1, high = positions[n - 1] - positions[0];
	while(low <= high) {
		int mid = (low + high) >> 1;

		if(isPossible(positions, n, c, mid))
			low = mid + 1;
		else
			high = mid - 1;
	}

	return high;
}