/*
Given a binary tree, check whether the tree is height balanced or not.
[Brute force -- At each node compute left and right height and then check whether it is balanced or not -- complex recursion -- O(N^2)]
[Optimal -- Add simple conditions while finding the height of the tree -- If at any moment we find tree is not balanced just return -1 
 or else return the height of the tree.]

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
int dfsHeight(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1)
        return -1;

    int rh = dfsHeight(root->right);
    if(rh == -1)
        return -1;

    if(abs(lh - rh) > 1) 
        return -1;
    
    return max(lh, rh) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return dfsHeight(root) != -1;
}

