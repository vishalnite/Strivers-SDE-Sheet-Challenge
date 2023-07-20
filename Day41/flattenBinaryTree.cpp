/*
Flatten a binary tree to a linked list. Convert preorder traversal to a linked list. The right of each node should point to the next node 
and the left should point to NULL.
[Do a reverse postorder traversal -- right left root -- Also maintain a global variable to store prevNode]

[Optimal solution -- constant space complexity]
[Based on Morris traversal -- connect last node to cur's right and cur's right to cur's left]

T.C - O(N)
S.C - O(1)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

// TreeNode<int> *prevNode = NULL;

// void flatten(TreeNode<int>* node) {
//     if(node == NULL) 
//         return;

//     flatten(node->right);
//     flatten(node->left);

//     node->right = prevNode;
//     node->left = NULL;

//     prevNode = node;
// }

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{   
    TreeNode<int> *cur = root;
    while(cur != NULL) {
        if(cur->left != NULL) {
            TreeNode<int> *prev = cur->left;

            while(prev->right) {
                prev = prev->right;
            }

            prev->right = cur->right;
            cur->right = cur->left;
        }
        cur = cur->right;
    }

    return root;
}