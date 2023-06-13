/*
Find quadruplet such that their sum is equal to the target. Pick unique indexes.
[Brute force -- Run 4 loops -- O(N^2)]
[Better -- Hashing -- O(N^3 * logN)]
[Optimal -- sort the array -- 2 pointer approach -- keep i & j constant]

T.C - O(N^3)
S.C - O(1) [Note other approaches uses a set to store unique quads]
*/

#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        for(int j = i + 1; j < n; j++) {
            if(j != i + 1 && arr[j] == arr[j - 1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum == target) {
                    return "Yes";
                }
                else if(sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }
    return "No";
}
