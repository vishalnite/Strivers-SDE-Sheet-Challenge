/*
Count the maximum number of consecutives 1's we can get by replacing atmost k 0's.

T.C - O(N)
S.C - O(1)
*/

int longestSubSeg(vector<int> &arr , int n, int k){
    int start = 0, end = 0;
    int maxLength = 0;
    int zeroes = 0;

    while(end < n) {
        if(arr[end] == 0) {
            zeroes++;
        }

        while(zeroes > k) {
          if(arr[start] == 0) {
            zeroes--;
          }
          start++;
        }

        maxLength = max(maxLength, end - start + 1);
        end++;
    }

    return maxLength;
}
