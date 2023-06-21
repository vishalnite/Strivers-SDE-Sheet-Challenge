/*
Find all the subset sum. Return it in sorted order.

T.C - O(2^N) + O(2^Nlog(2^N))
S.C - O(2^N)
*/

#include<bits/stdc++.h>

void generateSubsetSum(int idx, int sum, vector<int> &num, int n, vector<int> &sumSubset) {
	if(idx == n) {
		sumSubset.push_back(sum);
		return;
	}

	generateSubsetSum(idx + 1, sum + num[idx], num, n, sumSubset);

	generateSubsetSum(idx + 1, sum, num, n, sumSubset);
}

vector<int> subsetSum(vector<int> num){
	int n = num.size();
	vector<int> sumSubset;
	generateSubsetSum(0, 0, num, n, sumSubset);
	sort(sumSubset.begin(), sumSubset.end());
	return sumSubset;
}