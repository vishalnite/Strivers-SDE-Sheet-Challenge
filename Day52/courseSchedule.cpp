/*
Find the order in which the courses must be completed. If it is not possible then return an empty list.
The courses are given as ordered pair [a, b] where to take course a , b needs to be completed first.
[Detect cycle in a directed graph -- DFS can be used -- use topological sort -- a better method]
[Remember whenever we are asked what comes before something -- try to use topological sort]

T.C - O(N) + O(V + E)
S.C - O(N) + O{N}
*/

vector<int> findSchedule(int numCourses, vector<pair<int, int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses + 1);
    vector<int> indegree(numCourses + 1, 0);

    for(int i = 0; i < prerequisites.size(); i++) {
        int u = prerequisites[i].first;
        int v = prerequisites[i].second;

        adj[v].push_back(u);
        indegree[u]++;
    }

    queue<int> q;
    vector<int> topo;

    for(int i = 1; i < numCourses; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }

    if(topo.size() == numCourses)
        return topo;
    return {};
}