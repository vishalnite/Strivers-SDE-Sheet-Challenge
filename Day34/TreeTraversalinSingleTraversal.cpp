/*
Find inorder, preorder and postorder traversal in a single traversal.

T.C - O(3N)
S.C - O(3N)
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    
    if(root == NULL)
        return {};

    vector<int> preOrder, inOrder, postOrder;
    stack<pair<BinaryTreeNode<int>*, int>> st;

    st.push({root, 1});

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left) {
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2) {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right) {
                st.push({it.first->right, 1});
            }
        }
        else {
            postOrder.push_back(it.first->data);
        }
    }

    return {inOrder, preOrder, postOrder};

}