/*
Spanning Tree - A subgraph which includes N nodes and N - 1 edges.
Minimum Spanning Tree(MST) - A spanning tree with minimum sum of weights.

Prim's Algorithm -- Helps to find MST of a graph -- greedy approach
Put the first node with 0 weight in the priority queue.
If the node is visited, do not got to it adjacent nodes(gives TLE).
If it is not visited then mark it visited and increse the sum.
Go to all adjacent nodes and put it into priority queue if it is not visited.

T.C - O(ElogE) + O(ElogE)
S.C - O(E)
*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});
        
        int sum = 0;
        
        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node])
                continue;
            
            sum += wt;
            vis[node] = 1;
            
            for(auto it : adj[node]) {
                int edW = it[1];
                int adjNode = it[0];
                
                if(!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }
        
        return sum;
    }
};


