/*
Implement atoi() function in C/C++.
i.e, extract numbers from a string. If the first character is '-', it indicates that the number is -ve.

T.C - O(N)
S.C - O(1)
*/

#include <bits/stdc++.h> 
int atoi(string str) {
    int ans = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            int num = str[i] - '0';
            ans = ans * 10 + num;
        }
    }

    if(str[0] == '-') {
        ans = -1 * ans;
    }

    return ans;
}