/*
Find the city which has the minimum number of cities adjacent to it having distance not more than the given threshold.
If two cities have the same number of cities then return the maximum city number.
[Can be solved using both Floyd-Warshall Algorithm and Dijkstra's Algorithm]

T.C - O(N^3)
S.C - O(N^2)
*/

#include <bits/stdc++.h> 
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) 
{
	vector<vector<int>> dist(n, vector<int>(n, 1e9));

	for(int i = 0; i < n; i++)
		dist[i][i] = 0;

	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		int wt = edges[i][2];

		dist[u][v] = wt;
		dist[v][u] = wt;
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(dist[i][k] != 1e9 && dist[k][j] != 1e9) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	int maxCity = n;
	int cityNo = -1;

	for(int city = 0; city < n; city++) {
		int cnt = 0;
		for(int adjCity = 0; adjCity < n; adjCity++) {
			if(dist[city][adjCity] <= distanceThreshold) 
				cnt++;
		}

		if(cnt <= maxCity) {
			maxCity = cnt;
			cityNo = city;
		}
	}

	return cityNo;
}