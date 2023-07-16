/*
Find the vertical order traversal of the binary tree.
[Requires good knowledge of STL & DS]
[Consider x-axis as vertcals[-Inf to +Inf] ans y-axis as levels[0 to Inf]]

T.C - O(N) -- [if using multiset -- O(NlogN)]
S.C - O(N)
*/

#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;

    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        TreeNode<int> *node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].push_back(node->data);

        if(node->left) {
            q.push({node->left, {x - 1, y + 1}});
        }
        if(node->right) {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    for(auto p : nodes) {
        for(auto q : p.second) {
            for(auto r : q.second) {
                ans.push_back(r);
            }
        }
    }

    return ans;
}