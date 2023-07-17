/*
Find the path from root to the given node.
[Perfor inorder traversal -- if left or right subtree return true then return true]

T.C - O(N)
S.C - O(H)
*/

#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool getPath(TreeNode<int> *root, int x, vector<int> &ans) {
	if(root == NULL)
		return false;

	ans.push_back(root->data);

	if(root->data == x)
		return true;

	if(getPath(root->left, x, ans) || getPath(root->right, x, ans))
		return true;

	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
	getPath(root, x, ans);
	return ans;
}
