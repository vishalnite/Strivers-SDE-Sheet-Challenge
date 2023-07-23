/*
Implement a BST iterator. Implement two functions next() and hasNext().
[Brute force -- Store preorder traversal in a vector -- S.C - O(N)]
[Optimal -- Perform inorder traversal -- maintain a stack which stores only the left most elements]

T.C - O(1) [Average O(1) -- as we are also pushing the leftmost elements from the right side of a node]
S.C - O(H)
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

class BSTiterator
{   
    stack<TreeNode<int>*> st;

    void pushAll(TreeNode<int> *node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
    public:
        BSTiterator(TreeNode<int> *root)
        {
            pushAll(root);
        }

        int next()
        {
            TreeNode<int> *node = st.top();
            st.pop();
            pushAll(node->right);
            return node->data;
        }

        bool hasNext()
        {
            return !st.empty();
        }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/