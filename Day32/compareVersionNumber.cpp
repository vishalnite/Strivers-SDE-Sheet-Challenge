/*
Given two version numbers as a string of digits and '.', find which version is the latest.

T.C - O(N + M)
S.C - O(1)
*/

#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    int n1 = a.length();
    int n2 = b.length();
    int i = 0, j = 0;

    while(i < n1 || j < n2) {
        long long ver1 = 0, ver2 = 0;

        while(i < n1 && a[i] != '.') {
            ver1 = ver1 * 10 + (a[i] - '0');
            i++;
        }

        while(j < n2 && b[j] != '.') {
            ver2 = ver2 * 10 + (b[j] - '0');
            j++;
        }

        if(ver1 > ver2) 
            return 1;
        else if(ver2 > ver1)
            return -1;

        if(i < n1) i++;
        if(j < n2) j++;
    }

    return 0;
}