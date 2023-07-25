/*
Convert the given binary tree to DLL. The DLL should be inorder traversal of the tree.
[Reverse inorder traversal -- right root left -- maintain a global variable prev node -- 
 connect the cur node's right with prev node and prev node's left with cur node]

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
BinaryTreeNode<int> *prevNode = NULL;

void BTtoDLLHelper(BinaryTreeNode<int> *node) {
    if(node == NULL)
        return;

    BTtoDLLHelper(node->right);

    node->right = prevNode;
    if(prevNode) {
        prevNode->left = node;
    }

    prevNode = node;

    BTtoDLLHelper(node->left);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    prevNode = NULL;
    BTtoDLLHelper(root);
    root = prevNode;
    
    return root;
}