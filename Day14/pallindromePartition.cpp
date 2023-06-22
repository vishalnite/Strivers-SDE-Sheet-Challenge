/*
Return all the pallindrome partitioning. 

T.C - O(2^n * k * (n/2))
S.C - O(k * x)
*/

#include <bits/stdc++.h> 

bool isPallindrome(string s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void findPartitions(int idx, string s, int n, vector<string> &path, vector<vector<string>> &res) {
    if(idx == n) {
        res.push_back(path);
        return;
    }

    for(int i = idx; i < n; i++) {
        if(isPallindrome(s, idx, i)) {
            path.push_back(s.substr(idx, i - idx + 1));
            findPartitions(i + 1, s, n, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> res;
    vector<string> path;
    int n = s.size();
    findPartitions(0, s, n, path, res);
    return res;
}