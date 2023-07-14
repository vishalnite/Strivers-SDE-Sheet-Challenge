/*
Find the left view of a tree.
[Perform level order traversal]

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

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        ans.push_back(q.front()->data);
        int n = q.size();

        for (int i = 0; i < n; i++) {
            if (!q.empty()) {
                TreeNode<int> *node = q.front();

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);

                q.pop();
            }
        }
    }

    return ans;
}