/*
Floyd Warshall Algorithm -- Multi-source shortest path
Run three loops and find the minimum distance via all the other nodes [Much more like a brute force approach]
To detect cycles -- Check the source nodes and if they are less than 0 then negative cycle exists (matrix[i][i])

T.C - O(N^3)
S.C - O(N ^ 2)
*/

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 1e9));

    for(int i = 0; i < n; i++) {
        adjMatrix[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adjMatrix[u - 1][v - 1] = wt;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adjMatrix[i][k] != 1e9 && adjMatrix[k][j] != 1e9)
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }

    return adjMatrix[src - 1][dest - 1];
}