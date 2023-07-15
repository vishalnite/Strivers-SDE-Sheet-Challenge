/*
Find the height of the binary tree.
[Level order traversal as well as Recursion can be used but both of them have their worst cases.]
[Level order traversal -- when the binary tree is full or complete & Recursion -- when the binary tree is skew]

T.C - O(N)
S.C - O(H)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int maxDepth(TreeNode<int> *root) {
    if(root == NULL)
        return -1;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return max(lh, rh) + 1;
}