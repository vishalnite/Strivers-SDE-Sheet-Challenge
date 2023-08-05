/*
Find the minimum effort that can be taken to reach from source(0, 0) to destination(n - 1, m - 1). The effort taken to go from one cell to
another cell is the maximum of (difference of height, curr difference).
[use modified Djikstra's algorithm]

T.C - O(ElogV) - O(n * m * log(n * m))
S.C - O(n * m)
*/

int minimumTimeTakingPath(vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq;

    int n = heights.size();
    int m = heights[0].size();

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};

    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    dis[0][0] = 0;
    pq.push({0, {0, 0}});

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if(row == n - 1 && col == m - 1)
            return diff;

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);
                if(newEffort < dis[nrow][ncol]) {
                    dis[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            } 
        }
    }

    return 0;
}