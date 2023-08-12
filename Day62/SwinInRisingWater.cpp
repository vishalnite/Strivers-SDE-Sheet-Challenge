/*
Find the minimum time to reach from (0, 0) to (N - 1, N - 1).
[BFS + Min Heap]

T.C - O(N * N)
S.C - O(N * N)
*/

bool isValid(int row, int col, int n) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

int minimumTime(int n, vector<vector<int>> &a)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;
    pq.push({a[0][0], {0, 0}});

    int dr[] = {-1, 0, +1, 0};
    int dc[] = {0, -1, 0, +1};

    while(!pq.empty()) {
        int time = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if(row == n - 1 && col == n - 1)
            return time;

        for(int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(isValid(nrow, ncol, n) && !vis[nrow][ncol]) {
                int newTime = max(a[nrow][ncol], time);
                pq.push({newTime, {nrow, ncol}});
                vis[nrow][ncol] = 1;
            }
        }
    }

    return -1;
}

