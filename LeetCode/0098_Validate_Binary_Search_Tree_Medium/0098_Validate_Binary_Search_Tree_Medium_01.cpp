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
/**
 * https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
 * Think:
 *      1)  Using In-Order Traversal and then store the result in a temp array.
 *      2)  Check if the temp array is sorted in ascending order, if it is, then the tree is BST.
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {  
        TreeNode *prev = NULL;
        return solver(root, prev);
    }

private:
    bool solver(TreeNode *node, TreeNode *&prev) {
        if (node == NULL) {
            return true;
        }
  
        if (!solver(node->left, prev))
            return false;
        //printf("prev = %p\n", prev);
        if (prev != NULL && prev->val >= node->val) {
            //printf("(false) prev->val(%d) >= node->val(%d)\n", prev->val, node->val);
            return false;
        }
        prev = node;
        //printf("prev = %d\n", prev->val);
        return solver(node->right, prev);
    }
};