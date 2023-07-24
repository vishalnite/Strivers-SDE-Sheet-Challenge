/*
First serialize a binary tree into a string and then deserialize the string to produce the binary tree.
[level order traversal -- Also push leafs even if they are NULL]

T.C - O(N)
S.C - O(N)
*/

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
#include<bits/stdc++.h>

string serializeTree(TreeNode<int> *root)
{
    if(!root)
        return "";

    string s = "";
    queue<TreeNode<int>*> q;

    q.push(root);
    while(!q.empty()) {
        TreeNode<int> *curNode = q.front();
        q.pop();

        if(curNode == NULL) {
            s.append("#,");
        }
        else {
            s.append(to_string(curNode->data) + ',');
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }

    return s;
}

TreeNode<int>* deserializeTree(string &data)
{
    if(data.size() == 0)
        return NULL;

    stringstream s(data);
    string str;

    getline(s, str, ',');
    TreeNode<int> *root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<int> *node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#") {
            node->left = NULL;
        }
        else {
            TreeNode<int> *left = new TreeNode<int>(stoi(str));
            node->left = left;
            q.push(left);
        }

        getline(s, str, ',');
        if(str == "#") {
            node->right = NULL;
        }
        else {
            TreeNode<int> *right = new TreeNode<int>(stoi(str));
            node->right = right;
            q.push(right);
        }
    }

    return root;
}



