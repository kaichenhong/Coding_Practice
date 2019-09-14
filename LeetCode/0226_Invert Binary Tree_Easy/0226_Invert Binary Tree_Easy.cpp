/**
 *  LeetCode: 226. Invert Binary Tree (Easy)
 *
 *      Invert a binary tree.
 *
 *
 *      Example:    1.       4                           4
 *                         /   \                       /   \
 *                        2     7           =>        7     2
 *                       / \   / \                   / \   / \
 *                      1   3 6   9                 9   6 3   1
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  9 MB [100.00%])
 */


 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;

        invertTree(root->left);
        invertTree(root->right);

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};