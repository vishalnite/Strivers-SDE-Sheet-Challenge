/*
Given a string without spaces. Add spaces to the string such that each word of the resultant string belongs to the given dictionary.

T.C - O(N * 2 ^ N)
S.C - O(N * 2 ^ N)
*/

#include <bits/stdc++.h>

void solve(int ind, string t, string &s, vector<string> &ans, unordered_map<string, int> &dict) {
    if(ind == s.length()) {
        ans.push_back(t);
        return;
    }

    string a;
    for(int i = ind; i < s.length(); i++) {
        a += s[i];
        if(dict.find(a) != dict.end()) {
            if(t.length() == 0)
                solve(i + 1, t + a, s, ans, dict);
            else
                solve(i + 1, t + " " + a, s, ans, dict);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string, int> dict;
    for(auto i : dictionary) {
        dict[i]++;
    }

    vector<string> ans;
    string t;
    solve(0, t, s, ans, dict);
    return ans;
}