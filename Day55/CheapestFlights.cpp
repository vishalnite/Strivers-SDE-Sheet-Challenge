/*
Find the cheapest flights within k stops. 
[use modified Dijkstra's algorithm -- Use queue and by taking into consideration the number of stops]

T.C - O(E) [using queue]
S.C - O(V^2)
*/

int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains)
{
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < trains.size(); i++) {
        int u = trains[i][0];
        int v = trains[i][1];
        int wt = trains[i][2];

        adj[u].push_back({v, wt});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source, 0}});
    vector<int> dis(n, 1e9);
    dis[source] = 0;

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > K)
                continue;

        for(auto list : adj[node]) {
            int edW = list.second;
            int adjNode = list.first;

            if(cost + edW < dis[adjNode] && stops <= K) {
                dis[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }
    
    if(dis[destination] == 1e9)
        return -1;
    return dis[destination];
}