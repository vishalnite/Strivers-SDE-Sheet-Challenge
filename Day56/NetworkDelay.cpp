/*
Find the minimum that is required to each node in a network. If a node is not reachable then return -1.
[use Dijkstra's algorithm to find the shortest distance of each node from a source]

T.C - O(ElogV)
S.C - O(V^2)
*/

#include<queue>

int networkDelayTime(vector<vector<int>> &edges, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    vector<int> time(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    time[k] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int curTime = pq.top().first;
        pq.pop();

        for(auto iter : adj[node]) {
            int adjNode = iter.first;
            int edW = iter.second;

            if(curTime + edW < time[adjNode]) {
                time[adjNode] = curTime + edW;
                pq.push({time[adjNode], adjNode});
            }
        } 
    }  

    int maxTime = 0;
    for(int i = 1; i <= n; i++) {
        maxTime = max(time[i], maxTime);
    }

    if(maxTime == 1e9)
        return -1;
    return maxTime;
}