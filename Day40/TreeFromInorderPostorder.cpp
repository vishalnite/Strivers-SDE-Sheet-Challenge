/*
Construct a binary tree from inorder and postorder traversal.
[Same as inorder & preorder traversal]
[On the left part -- postorder is the number of elements from the start and On the right part -- the remaining elements]

T.C - O(N)
S.C - O(N)
*/

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>

TreeNode<int> *buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, 
int inStart, int inEnd, unordered_map<int, int> &mp) {
     
     if(inStart > inEnd || postStart > postEnd)
          return NULL;

     TreeNode<int> *root = new TreeNode<int>(postorder[postEnd]);

     int inRoot = mp[root->data];
     int num = inRoot - inStart;

     root->left = buildTree(postorder, postStart, postStart + num - 1, inorder, inStart, inRoot - 1, mp);
     root->right = buildTree(postorder, postStart + num, postEnd - 1, inorder, inRoot + 1, inEnd, mp);

     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
     // if(postorder.size() != inorder.size())
     //      return NULL;

	unordered_map<int, int> mp;

     for(int i = 0; i < inorder.size(); i++) {
          mp[inorder[i]] = i;
     }

     TreeNode<int>* root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);

     return root;
}
