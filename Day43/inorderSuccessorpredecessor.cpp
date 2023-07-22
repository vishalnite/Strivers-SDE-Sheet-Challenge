/*
Find inorder successor and predecessor in a BST.
[Move left and right as required]

T.C - O(H)
S.C - O(1)
*/

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

int findSuccessor(BinaryTreeNode<int> *root, int key) {
    int successor = -1;
    
    while(root != NULL) {
        if(key >= root->data) {
            root = root->right;
        } 
        else {
        successor = root->data;
        root = root->left;
        }
    }

    return successor;
}

int findPredecessor(BinaryTreeNode<int> *root, int key) {
    int predecessor = -1;

    while(root != NULL) {
        if(key > root->data) {
            predecessor = root->data;
            root = root->right;
        } 
        else {
        root = root->left;
        }
    }

    return predecessor;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int successor = findSuccessor(root, key);
    int predecessor = findPredecessor(root, key);

    return {predecessor, successor};
}
