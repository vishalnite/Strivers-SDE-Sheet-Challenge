/*
Find the longest palindromic substring.
[Using DP -- can be done more optimally using centre expansion or Manacher's algorithm]

T.C - O(N^2)
S.C - O(N^2)
*/

#include<bits/stdc++.h>

string longestPalinSubstring(string str)
{
    int n = str.length();

    if(n == 0) 
        return "";

    vector<vector<int>> dp (n, vector<int> (n, 0));

    int len =  1;
    int start = 0, end = 0;

    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;

        if(i < n - 1 && str[i] == str[i + 1]) {
            dp[i][i + 1] = 1;
            if(len != 2) {
                len = 2;
                start = i;
                end = i + 1;
            }
        }
    }

    int temp = n - 2;
    int j = 2;
    while(temp > 0) {
        for(int i = 0; i < temp; i++) {
            if(str[i] == str[i + j] && dp[i + 1][i + j - 1] == 1) {
                dp[i][i + j] = 1;
                if(len < j + 1) {
                    len = j + 1;
                    start = i;
                    end = i + j;
                }
            }
        }
        temp--;
        j++;
    }
    

    string ans = "";
    for(int i = start; i <= end; i++) {
        ans += str[i];
    }

    return ans;

}