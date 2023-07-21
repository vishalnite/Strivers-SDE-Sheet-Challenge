/*
Find the Kth largest element from the BST.
[Reverse Inorder traversal of BST]

T.C - O(N)
S.C - O(N) [O(1) -- Morris Inorder Traversal]
*/

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

void findkthLargest(TreeNode<int> *root, int &k, int &ans) {
    if(root == NULL) {
        return;
    }

    findkthLargest(root->right, k, ans);

    k--;
    if(k == 0) {
        ans = root->data;
        return;
    }

    findkthLargest(root->left, k, ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    findkthLargest(root, k, ans);
    return ans;
}
