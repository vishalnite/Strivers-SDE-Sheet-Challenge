/*
Morris Inorder Traversal.
[Threaded binary tree -- create threads at the last node of a subtree to move back to the root]

T.C - O(N) [amortized]
S.C - O(1)
*/

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *cur = root;

    while(cur != NULL) {
        if(cur->left == NULL) {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else {
            TreeNode *prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }

    return inorder;
}