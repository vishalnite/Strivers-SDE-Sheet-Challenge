/*
Check whether the tree is symmetric(Mirror Image) or not.
[Treversal at left and right subtree -- when moving left simultaneously move right]

T.C - O(N)
S.C - O(N)
*/

/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool isSymmetricHelp(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right) {
    if(left == NULL || right == NULL)
        return (left == right);

    if(left->data != right->data)
        return false;

    return (isSymmetricHelp(left->left, right->right)
        && isSymmetricHelp(left->right, right->left)
        );
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    return (root == NULL || isSymmetricHelp(root->left, root->right));    
}