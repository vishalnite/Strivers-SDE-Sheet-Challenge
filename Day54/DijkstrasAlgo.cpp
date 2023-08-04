/*
Find the shortest distance to all nodes from a source node.
[Use Dijkstra's algorithm -- If we get a lesser distance from a path than the current distance, then replace -- BFS]
[Can be solved using QUEUE, PRIORITY_QUEUE, SET]
[Time take -- QUEUE > PRIORITY_QUEUE > SET]
[In set method, we erase the node which is already visited -- this ensures that we do not explore that path bcoz we got somthing better]

T.C - O(E * logE) -- Priority Queue
    - O(E * logV) -- Set
S.C - O(2V)
*/

/* ---------------------- PRIORITY QUEUE -------------------- */
vector<int> dijkstra(vector<vector<int>> &edge, int v, int e, int src)
{
    // 'edge' contains {u, v, distance} vectors.
    vector<vector<pair<int, int>>> adj(v);
    for(int i = 0; i < e; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, 1e9);
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if(dis + edgeWt < dist[adjNode]) {
                dist[adjNode] = dis + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}


/* ---------------------- SET -------------------- */
vector<int> dijkstra(vector<vector<int>> &edge, int v, int e, int src)
{
    // 'edge' contains {u, v, distance} vectors.
    vector<vector<pair<int, int>>> adj(v);
    for(int i = 0; i < e; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    set<pair<int, int>> st;
    vector<int> dist(v, 1e9);
    st.insert({0, src});
    dist[src] = 0;

    while(!st.empty()) {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);
        
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if(dis + edgeWt < dist[adjNode]) {
                if(dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}