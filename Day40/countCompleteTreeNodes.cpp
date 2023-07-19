/*
Find the number of nodes in a complete tree.
[Brute force -- Do any traversal]
[Optimal approach -- Use the property of the complete tree -- If a subtree is a perfect tree(lh == rh) then the number of nodes is (2^h - 1) -- h(height)]
[Also while returning, do 1 + (left's val) + (right's val)]

T.C - O((logN)^2)
S.C - O(logN)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int findLeftHeight(TreeNode *root) {
        int height = 0;
        while(root) {
            height++;
            root = root->left;
        }

        return height;
    }

    int findRightHeight(TreeNode *root) {
        int height = 0;
        while(root) {
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};