/*
Find the lowest common ancestor for the given two nodes of the binary tree.
[Traverse left and right -- If one of them returns NULL, return the other one -- If both of them do not return NULL, return the root value]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(root == NULL) {
        return -1;
    }

    if(root->data == x || root->data == y) {
        return root->data;
    }

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    if(left == -1) {
        return right;
    }
    else if(right == -1) {
        return left;
    }
    else {
        return root->data;
    }
}