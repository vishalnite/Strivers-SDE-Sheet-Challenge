/*
Sort an array containing 0s, 1s and 2s.
Use Dutch Natinal flag algorithm.
Three pointer, low, mid, high
Run a loop until (mid <= high)
[0...low - 1] -> 0
[low...mid - 1] -> 1
[mid...high] -> unsorted part
[high + 1...N - 1]

T.C - O(N)
S.C - O(1)
*/

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low = 0, mid = 0, high = n - 1;
   while(mid <= high) {
      if(arr[mid] == 0) {
         swap(arr[low], arr[mid]);
         low++;
         mid++;
      }
      else if(arr[mid] == 1) {
         mid++;
      }
      else {
         swap(arr[mid], arr[high]);
         high--;
      }
   }
}