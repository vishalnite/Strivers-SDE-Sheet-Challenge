/*
Kruskal's Algorithm -- Helps to find MST -- Uses Disjoint Set

T.C - O(ElogE) + O(E * 4a * 2)
S.C - O(E)
*/

#include<bits/stdc++.h>

class DisjointSet {
    vector<int> parent, size;
    public:
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for(int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUParent(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v)
                return;
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v]; 
            }
        }
};

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<pair<int, pair<int, int>>> graph;
  for(auto edge : edges) {
    graph.push_back({edge[2], {edge[0], edge[1]}});
  }

  sort(graph.begin(), graph.end());

  DisjointSet ds(n);
  int mst = 0;

  for(auto it : graph) {
    int wt = it.first;
    int u = it.second.first;
    int v = it.second.second;

    if(ds.findUParent(u) != ds.findUParent(v)) {
      mst += wt;
      ds.unionBySize(u, v);
    }
  }

  return mst;
}

