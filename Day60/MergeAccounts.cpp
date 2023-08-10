/*
Merge the mails that belong to the same person.
[Not very intuitive in the first place -- Solved using Disjoint set]

T.C - O(N * M * 4a)
S.C - O(N * M)
*/

class DisjointSet {
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
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

        void unionByRank(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v)
                return;
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapAccNode;

        //To map Each mail with their node value
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(mapAccNode.find(mail) == mapAccNode.end()) {
                    mapAccNode[mail] = i;
                }
                else {
                    ds.unionBySize(i, mapAccNode[mail]);
                }
            }
        }

        //Merging mails that belong to the same person
        vector<string> mergedAcc[n];
        for(auto it : mapAccNode) {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedAcc[node].push_back(mail);
        }

        //Storing answer in required format
        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(mergedAcc[i].size() == 0)
                continue;

            sort(mergedAcc[i].begin(), mergedAcc[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto it : mergedAcc[i])
                temp.push_back(it);
            ans.push_back(temp);
        }

        return ans;
    }
};