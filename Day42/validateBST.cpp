/*
Verify whether the given Binary tree is a valid BST.
[At each node keep a range and check  whether it lies in that range]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

bool isValidBST(BinaryTreeNode<int> *root, long long minVal, long long maxVal) {
    if(root == NULL) {
        return true;
    }

    if(root->data < minVal || root->data > maxVal) {
        return false;
    }

    return isValidBST(root->left, minVal, root->data)
        && isValidBST(root->right, root->data, maxVal);
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}