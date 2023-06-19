/*
Given the arrival and departure time of trains. Determine the maximum number of platforms required in a day.

T.C - O(2*NlogN) + O(2N)
S.C - O(1)
*/

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);

    int currPlatforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;

    while(i < n && j < n) {
        if(at[i] <= dt[j]) {
            currPlatforms++;
            i++;
        }
        else if(at[i] > dt[j]) {
            currPlatforms--;
            j++;
        }

        maxPlatforms = max(maxPlatforms, currPlatforms);
    }

    return maxPlatforms;
}