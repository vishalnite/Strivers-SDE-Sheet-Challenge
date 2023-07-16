/*
Find the top view of the tree.
[Do level order traversal and find the first element that appears in a vertical line.]
[Prefer level order because recursion will require us to implement the logic of height of the tree as well.]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        TreeNode<int>* node = q.front().first;
        int line = q.front().second;
        q.pop();

        if(mp.find(line) == mp.end()) 
            mp[line] = node->val;

        if(node->left)
            q.push({node->left, line - 1});
        if(node->right)
            q.push({node->right, line + 1});
    }

    for(auto it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}