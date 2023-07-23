/*
2 sum problem in BST.
[Naive approach -- Store inorder traversal in a vector -- it boils down to simple 2 sum problem]
[Optimal approach -- use BST iterator concept -- maintain a next iterator and before iterator]

T.C - O(N)
S.C - O(2H)
*/

#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

class BSTIterator {
    stack<BinaryTreeNode<int>*> st;
    bool reverse = false;

    void pushAll(BinaryTreeNode<int> *node) {
        while(node) {
            st.push(node);
            if(!reverse) 
                node = node->left;
            else 
                node = node->right;
        }
    }

    public:
        BSTIterator(BinaryTreeNode<int> *root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }
        
        bool hasNext() {
            return !st.empty();
        }

        int next() {
            BinaryTreeNode<int> *node = st.top();
            st.pop();
            if(!reverse)
                pushAll(node->right);
            else
                pushAll(node->left);
            return node->data;
        }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while(i < j) {
        if(i + j == k) 
            return true;
        else if(i + j > k) 
            j = r.next();
        else    
            i = l.next();
    }

    return false;
}