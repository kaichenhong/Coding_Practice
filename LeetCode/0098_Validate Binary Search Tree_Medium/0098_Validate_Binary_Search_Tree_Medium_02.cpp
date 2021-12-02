/**
 *  LeetCode: 98. Validate Binary Search Tree (Medium)
 *
 *      Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 *      Assume a BST is defined as follows:
 *          The left subtree of a node contains only nodes with keys less than the node's key.
 *          The right subtree of a node contains only nodes with keys greater than the node's key.
 *          Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *      Example:    1.  [2,1,3]  =>  true
 *                  2.  [5,1,4,null,null,3,6]  =>  false;   The root node's value is 5 but its right child's value is 4.
 *
 *
 *
 *  Results:    AC (8 ms [98.53%];  20.4 MB [97.92%])
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
    bool isValidBST(TreeNode* root) {
        return checkNode(root, nullptr, nullptr);
    }

private:
    bool checkNode(const TreeNode *node, const int *p_min, const int *p_max) {
        if (node == NULL)
            return true;

        if (p_min && *p_min >= node->val)
            return false;
        if (p_max && *p_max <= node->val)
            return false;

        return checkNode(node->left, p_min, &node->val) && checkNode(node->right, &node->val, p_max);
    }
};
