/*
Find the majority element in the array. Majority element - occurence more than size/2.

T.C - O(N) [if the array contains the majority element for sure]
    - O(2N) [if the array may not contain majority element]
S.C - O(1)
*/

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int count = 0, majorElem;
	for(int i = 0; i < n; i++) {
		if(count == 0) {
			majorElem = arr[i];
			count = 1;
		}
		else if(arr[i] == majorElem) {
			count++;
		}
		else {
			count--;
		}
	}

	count = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == majorElem) {
			count++;
		}
	}

	if(count > (n / 2))
		return majorElem;
	return -1;

}