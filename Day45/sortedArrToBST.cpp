/*
Convert the given sorted array into a balanced BST.
[Use Binary search -- make mid element as the root -- recursively build the left and right nodes]

T.C - O(N)
S.C - O(1) [not considering auxiliary space]
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

TreeNode<int> *BSTHelper(vector<int> &arr, int l, int r) {
    
    if(l > r)
        return NULL;

    int mid = (l + r) >> 1;

    TreeNode<int> *node = new TreeNode<int>(arr[mid]);
    node->left = BSTHelper(arr, l, mid - 1);
    node->right = BSTHelper(arr, mid + 1, r);

    return node;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    if(n == 0) {
        return NULL;
    }

    TreeNode<int> *root = BSTHelper(arr, 0, n - 1);

    return root;
}