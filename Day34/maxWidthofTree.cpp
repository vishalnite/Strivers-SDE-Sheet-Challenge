/*
Find the maximum width of the given binary tree. Width is the number of elements in a level.

[using level orde traversal]
T.C - O(N)
S.C - O(N)
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

int getMaxWidth(TreeNode<int> *root)
{
    int maxWidth = 0;

    if(root == NULL)
        return 0;

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        maxWidth = max(maxWidth, n);

        for(int i = 0; i < n; i++) {
            TreeNode<int> *node = q.front();

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            
            q.pop();
        }
    }

    return maxWidth;
}