/*
Find the order in which the charcters are placed in an alien dictionary. It contains k number of characters.
[We need to find what comes before what -- topological sort]
[Find the unequal characters between pairs of strings in the dictionary]
[To find when it is not possible -- If it contains a cycle -- If the 1st string is larger in size and it matches with all characters in string 2]

T.C - O(N) + O(V + E)
S.C - O(N) + O(N)
*/

vector<vector<int>> adj(k);

    for(int i = 0; i < dictionary.size() - 1; i++) {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];
        int len = min(s1.size(), s2.size());

        for(int ptr = 0; ptr < len; ptr++) {
            if(s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> indegree(k, 0);
    for(int i = 0; i < k; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> topo; 
    for(int i = 0; i < k; i++) {
        if(indegree[i] == 0)
            q.push(i);
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

    string ans = "";
    for(auto it : topo) {
        ans += char(it + 'a');
    }

    return ans;