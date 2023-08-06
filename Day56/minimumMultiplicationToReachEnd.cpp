/*
Find the minimum multiplications required to reach end. Take mod = 1000 for every multiplication. 
[The main thing to catch is that we need distance array from 0 to 999 as mod = 10^3]
[If we get this then it is a simple Dijkstra's algorithm problem]

T.C - O(10^3 * array size) [Very hypothetical situation]
S.C - O(10^3)
*/

int minimumOperations(int n, int start, int end, vector<int> &a)
{
    if(start == end)
        return 0;
        
    int mod = 1000;
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int> dis(1000, 1e9);
    dis[start] = 0;

    while(!q.empty()) {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for(auto i : a) {
            int num = (node * i) % mod;
            if(steps + 1 < dis[num]) {
                dis[num] = steps + 1;
                if(num == end)
                    return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }

    return -1;
}