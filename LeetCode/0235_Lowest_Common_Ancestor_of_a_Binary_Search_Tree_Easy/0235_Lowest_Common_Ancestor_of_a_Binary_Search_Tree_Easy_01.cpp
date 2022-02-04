/*
 *  Results:    AC (28 ms [89.23%];  23.2 MB [92.93%])
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
    /* using the characteristic of BST to solve the problem */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* case 1 */
        if ((root->val > p->val) && (root->val > q->val))
            return lowestCommonAncestor(root->left, p, q);
        /* case 2 */
        if ((root->val < p->val) && (root->val < q->val))
            return lowestCommonAncestor(root->right, p, q);
        /* find out => (p->val / root->val / q->val) */
        return root;
    }
};

