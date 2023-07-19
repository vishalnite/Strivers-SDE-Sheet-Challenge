/*
Construct a binary tree from Inorder and Preorder traversal.
[Recursive function that splits the left subpart and right subpart in inorder using the root from preorder]

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

TreeNode<int> *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart,
int preEnd, unordered_map<int, int> &mp) {
    if(inStart > inEnd || preStart > preEnd)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);

    int inRoot = mp[root->data];
    int num = inRoot - inStart;

    root->left = buildTree(inorder, inStart, inRoot - 1, preorder, preStart + 1, preStart + num, mp);
    root->right = buildTree(inorder, inRoot + 1, inEnd, preorder, preStart + num + 1, preEnd, mp);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int, int> mp;

    for(int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    TreeNode<int> *root = buildTree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, mp);
    
    return root;
}