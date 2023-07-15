/*
Find the diameter of a tree. Diameter is the longest path between two nodes. It need not pass through the root node.
[Brute force -- At each node find the left and right height and then compute diameter -- O(N^2)]
[Optimal -- while finding the height of the tree, also compute the diameter]
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

int height(TreeNode<int> *root, int &diameter) {
    if(root == NULL)
        return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return max(lh, rh) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diameter = 0;
    height(root, diameter);
    return diameter;
}
