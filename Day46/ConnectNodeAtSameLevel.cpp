/*
Connect nodes at the same level.
[Perform level order traversal and connect the next pointer]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    if(root == NULL)
        return;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            if(i != size - 1) {
                BinaryTreeNode<int> *nextNode = q.front();
                node->next = nextNode;
            }
            else {
                node->next = NULL;
            }

            if(node->left) 
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
}