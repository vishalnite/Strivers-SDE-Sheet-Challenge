/*
Find the boundary traversal of the binary tree.
[Put root first and then -- leftBoundary(excluding Leaf) + rightBoundary(excluding Leaf) + leafNodes]

T.C - O(H) + O(H) + O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int> *node) {
    return !node->left && !node->right;
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &res) {
    TreeNode<int> *cur = root->left;
    
    while(cur) {
        if(!isLeaf(cur))
            res.push_back(cur->data);
        if(cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(TreeNode<int> *root, vector<int> &res) {
    TreeNode<int> *cur = root->right;
    vector<int> temp;
    int size = 0;

    while(cur) {
        if(!isLeaf(cur)) {
            temp.push_back(cur->data);
            size++;
        }
        if(cur->right)
            cur = cur->right;
        else 
            cur = cur->left;
    }

    for(int i = size - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

void addLeafNodes(TreeNode<int> *root, vector<int> &res) {
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }

    if(root->left)
        addLeafNodes(root->left, res);
    if(root->right)
        addLeafNodes(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(root == NULL)
        return res;

    if(!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeafNodes(root, res);
    addRightBoundary(root, res);

    return res;
}