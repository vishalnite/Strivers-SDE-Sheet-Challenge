/*
Use KMP algorithm for pattern matching.
[KMP -- proper prefix matches suffix -- build LPS(Longest Prefix Suffix) -- No need to match the characters which already matches]

T.C - O(N - M + 1) -- worst case - O(N^2)
S.C - O(M)
*/

#include <bits/stdc++.h> 

void computeLPS(vector<int> &lps, string p, int m) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < m) {
        if(p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool findPattern(string p, string s)
{
    int n = s.length();
    int m = p.length();

    vector<int> lps(m);
    computeLPS(lps, p, m);

    int i = 0, j = 0;
    while((n - i) >= (m - j)) {
        if(s[i] == p[j]) {
            i++;
            j++;
        }

        if(j == m) {
            return true;
        }
        else if(i < n && s[i] != p[j]) {
            if(j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return false;
}