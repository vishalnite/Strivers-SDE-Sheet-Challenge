/*
Given n days. A student has to read m chapters in n days. The time required for each chapter is given in time[] array. 
Find the maximum time the student has to read in order to read all the chapters in exactly n days.

T.C - O(NlogN)
S.C - O(1)
*/

#include <bits/stdc++.h>

bool isPossible(int n, int m, vector<int> &time, long long mid) {
	int days = 1;
	long long sum = 0;
	for(int i = 0; i < m; i++) {
		if(time[i] > mid) return false;
		if(sum + time[i] > mid) {
			days++;
			sum = time[i];
		}
		else {
			sum += time[i];
		}
	}
	if(days > n)
		return false;
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long sum = 0; 
	int minTime = INT_MAX;
	for(int t : time) {
		sum += t;
		minTime = min(minTime, t);
	}

	long long low = minTime, high = sum;

	while(low <= high) {
		long long mid = (low + (high - low) / 2);
		
		if(isPossible(n, m, time, mid)) {
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return low;
}