/*
Given a matrix with sorted rows. Find the median of the matrix.

T.C - O(log(2^32) * N * log(M)) = O(32 * N * log(M))
S.C - O(1)
*/

int countSmallerThanEqualToMid(vector<int> &row, int mid) {
    int l = 0, h = row.size() - 1;
    while(l <= h) {
        int md = (l + h) >> 1;

        if(row[md] <= mid) l = md + 1;
        else h = md - 1;
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 1, high = 1e9;
    int mid;

    while(low <= high) {
        mid = (low + high) >> 1;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            cnt += countSmallerThanEqualToMid(matrix[i], mid);
        }

        if(cnt <= ((n * m) / 2)) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}