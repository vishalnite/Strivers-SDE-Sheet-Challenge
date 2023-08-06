/*
Find the number of shortest paths to reach from 0 to N - 1.
[Use Dijkstra's algorithm]
[But we also need to keep track of the number of shortest ways to reach the previous node --  a kind of backtracking]
[The number of ways will be stored in ways[] array -- If we reached the node with a shorter distance before then just add it]
[Since answer is very large so do % 1e9 + 7]

T.C - O(ElogV)
S.C - O(V^2)
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long, long>>> adj(n);
        for(int i = 0; i < roads.size(); i++) {
            long u = roads[i][0];
            long v = roads[i][1];
            long wt = roads[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        pq.push({0, 0});
        vector<long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int MOD = 1e9 + 7;

        while(!pq.empty()) {
            long dis = pq.top().first;
            long node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                long adjNode = it.first;
                long edW = it.second;

                if(dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        } 

        return ways[n - 1] % MOD;
    }
};