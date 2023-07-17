/*
Find the bottom view of the binary tree.
[same as top view of a binary tree except update the new value at a line]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    if(root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        BinaryTreeNode<int> *node = q.front().first;
        int line = q.front().second;
        q.pop();

        mp[line] = node->data;

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
