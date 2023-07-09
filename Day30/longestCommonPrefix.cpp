/*
Find the longest common prefix from the array of strings.
[using sorting]

T.C - O(NlogN) + O(N)
S.C - O(1)
*/

#include<algorithm>

string longestCommonPrefix(vector<string> &arr, int n)
{
    string longestPrefix = "";
    sort(arr.begin(), arr.end());

    string first = arr[0];
    string last = arr[n - 1];

    int i = 0;
    while(first[i] == last[i]) {
        longestPrefix += first[i];
        i++;
    }

    return longestPrefix;
}


