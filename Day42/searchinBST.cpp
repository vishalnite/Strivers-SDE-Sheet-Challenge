/*
Search a given key in Binary Search Tree(BST).
[Always the height of binary tree id logN. So the time complexity to search an element is logN]

T.C - O(logN)
S.C - O(1)
*/

#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root != NULL && root->data != x) {
        root = root->data > x ? root->left : root->right;
    }

    return root;
}