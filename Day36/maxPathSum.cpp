/*
Find the maximum path sum between two leaf nodes. The node values are non negative. If the tree has only one leaf node then return -1.
It is a slight variation of the maximum path sum problem which also has -ve node values.
[Remember when -ve values are there do not take leftSum and rightSum values as -ve, instead take 0]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int maxPathDown(TreeNode<int> *node, long long &maxi) {
    if(node == NULL)
        return 0;

    long long leftSum = maxPathDown(node->left, maxi);
    long long rightSum = maxPathDown(node->right, maxi);

    maxi = max(maxi, node->val + leftSum + rightSum);

    return node->val + max(leftSum, rightSum);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root || !root->left || !root->right)
        return -1;
        
    long long maxi = LONG_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

