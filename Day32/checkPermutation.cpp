/*
Given two strings, check whether one string is an anagram of another string.
[Brute force -- use sorting -- O(NlogN)]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    
    int n1 = str1.length();
    int n2 = str2.length();

    if(n1 != n2)
        return false;

    unordered_map<char, int> mp;

    for(int i = 0; i < n1; i++) {
        mp[str1[i]]++;
        mp[str2[i]]--;
    }

    for(auto it : mp) {
        if(it.second != 0) 
            return false;
    }

    return true;
}