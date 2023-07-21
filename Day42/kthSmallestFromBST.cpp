/*
Find the Kth smallest element from the BST.
[Inorder traversal of BST is sorted]

T.C - O(N)
S.C - O(N) [O(1) -- Morris Inorder Traversal]
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

void findkthSmallest(TreeNode<int> *root, int &k, int &ans) {
    if(root == NULL) {
        return;
    }

    findkthSmallest(root->left, k, ans);

    k--;
    if(k == 0) {
        ans = root->data;
        return;
    }

    findkthSmallest(root->right, k, ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = -1;
	findkthSmallest(root, k, ans);
    return ans;
}