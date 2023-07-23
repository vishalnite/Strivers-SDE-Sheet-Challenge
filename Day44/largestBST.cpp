/*
Find the largest BST that can be obtained from a given binary tree.
[Brute force -- Validate BST at each node and if it is valid calculate its size -- O(N^2)]
[Optimal -- Keep a track of minVal, maxVal & maxSize -- start from the bottom -- if it satisfies BST update size as 1 + left.maxSize + right.maxSize]

T.C - O(N)
S.C - O(1)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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

class NodeValue {
    public:
        int maxNode, minNode, maxSize;

        NodeValue(int minNode, int maxNode, int maxSize) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
};

NodeValue largestBSTHelper(TreeNode<int> *root) {
    if(root == NULL) {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    NodeValue left = largestBSTHelper(root->left);
    NodeValue right = largestBSTHelper(root->right);

    if(left.maxNode < root->data && right.minNode > root->data) {
        return NodeValue(min(left.minNode, root->data), max(right.maxNode, root->data), 
        left.maxSize + right.maxSize + 1);
    }

    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBST(TreeNode<int>* root) 
{
    return largestBSTHelper(root).maxSize;
}
