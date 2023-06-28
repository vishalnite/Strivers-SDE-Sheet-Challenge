/*
Find k max sum commbinations from the given arrays A and B, each of size N. By sum we mean pair sum.

T.C - O(NlogN) + O(NlogN) + O(KlogK)
S.C - O(K) + O(K)
*/

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	priority_queue<pair<int, pair<int, int>>> pq;
	set<pair<int, int>> st;

	int sum = a[0] + b[0];
	pq.push({sum, {0, 0}});
	st.insert({0, 0});

	vector<int> ans;
	for(int x = 0; x < k; x++) {
		auto pr = pq.top();
		sum = pr.first;
		int i = pr.second.first;
		int j = pr.second.second;

		ans.push_back(sum);
		pq.pop();

		if(i + 1 < n && st.find({i + 1, j}) == st.end()) {
            pq.push({a[i + 1] + b[j], {i + 1, j}});
            st.insert({i + 1, j});
		}
		if(j + 1 < n && st.find({i, j + 1}) == st.end()) {
            pq.push({a[i] + b[j + 1], {i, j + 1}});
            st.insert({i, j + 1});
		}
	}

	return ans;
}