/*
Same as word ladder problem, but also need to print all the shorter sequences.
[Use BFS -- In queue store sequences -- only delete the word from set after each level]
[Gives memory limit exceeds in Leetcode -- Optimized through DFS + Backtracking -- Not required in Interviews]

T.C - O(N * word length * 26 * [logN])
S.C - cannot be determined -- it will depend on the number of sequences obtained
*/

#include<unordered_set>
#include<queue>

vector<vector<string>> shortestTransitionPaths(string start, string finish, vector<string>& wordPool)
{
    int len = start.size();
    queue<vector<string>> q;
    unordered_set<string> st(wordPool.begin(), wordPool.end());
    q.push({start});
    st.erase(start);

    int level = 0;
    vector<string> usedOnLevel;
    usedOnLevel.push_back(start);
    vector<vector<string>> ans;

    while(!q.empty()) {
        vector<string> vec = q.front();
        q.pop();

        //To delete used words in a level
        if(vec.size() > level) {
            level++;
            for(auto it : usedOnLevel) {
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        //To insert sequences on only shorter length
        string word = vec.back();
        if(word == finish) {
            if(ans.size() == 0) {
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }
        
        for(int i = 0; i < len; i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()) {
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                } 
            }
            word[i] = original;
        }
    }

    return ans;
}