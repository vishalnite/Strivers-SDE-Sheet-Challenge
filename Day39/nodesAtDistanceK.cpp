/*
Find all the nodes which are at a distance K from the given node.
[We are also required to move upward -- store parent of each node in a map]
[From the target node move radially by one step(left, right, parent) and also keep track whether the node is visited or not]

T.C - O(N) + O(N)
S.C - O(N) + O(N) + O(N)
*/

/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
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

#include<bits/stdc++.h>

void mark_parents(BinaryTreeNode<int> *root,  unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &parent_track) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        BinaryTreeNode<int> *node = q.front();
        q.pop();

        if(node->left) {
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int k) {
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent_track;
    mark_parents(root, parent_track);

    queue<BinaryTreeNode<int> *> q;
    unordered_map<BinaryTreeNode<int>*, bool> visited;
    q.push(target);
    visited[target] = true;
    int cur_level = 0;

    while(!q.empty()) {
        int size = q.size();
        if(cur_level == k)
            break;
        cur_level++;

        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            if(node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parent_track[node] && !visited[parent_track[node]]) {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }

    vector<BinaryTreeNode<int> *> ans;
    while(!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}