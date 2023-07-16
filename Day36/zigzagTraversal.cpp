/*
FInd the Zig-Zag traversal for the given tree.
[Do level order traversal and keep a flag to know which level to put in alternating fashion]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL)    
        return ans;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);

        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            int index = (leftToRight ? i : size - i - 1);
            row[index] = node->data;

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        leftToRight = !leftToRight;

        for(int i = 0; i < size; i++) {
            ans.push_back(row[i]);
        }
    }

    return ans;
}
