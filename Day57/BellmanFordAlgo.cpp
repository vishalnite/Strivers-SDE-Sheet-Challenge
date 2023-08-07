/*
Bellman-Ford Algorithm -- To find all pair shortest path when the graph contains negative cycle. [Solves Dijkstra's problem]
To apply it in undirected graph, convert it into directed graph by putting two directed edges in place of one undirected edge.
[Relax all the edges for N - 1 time]
[Why N - 1 times -- Because at the worst case the source node can be at the bottom]
[Negative cycle detection -- Do relaxation for Nth time and if the distance still relaxes then there is a cycle]
[Takes more time than Dijkstra's algorithm -- Quadratic T.C]

T.C - O(E * V)
S.C - O(V)
*/

#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    for(int i = 1; i < n; i++) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist[dest];
}