/*
Construct a BST when its preorder traversal is given.
[Brute force -- Construct BST taking nodes one by one -- O(N*N)]
[Better approach -- Find inorder traversal by sorting the preorder traversal -- construct BT using inorder & preorder -- O(NlogN)]
[Optimal approach -- using validate a BST intuition -- Maintain an upper bound and decide whether to put the node in left or right]

T.C - O(3N) ~ O(N) [we are visiting a node atmost 3 times]
S.C - O(1) [Not considering auxiliary space]
*/

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int> *build(vector<int> &preorder, int &i, int bound) {
    if(i == preorder.size() || preorder[i] > bound) {
        return NULL;
    }

    TreeNode<int> *node = new TreeNode<int>(preorder[i++]);
    node->left = build(preorder, i, node->data);
    node->right = build(preorder, i, bound);

    return node;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i = 0;
    return build(preOrder, i, INT_MAX);
}