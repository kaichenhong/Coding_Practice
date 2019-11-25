/**
 *  LeetCode: 94. Binary Tree Inorder Traversal (Medium)
 *
 *      Given a binary tree, return the inorder traversal of its nodes' values.
 *
 *      Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 *
 *
 *      Example:    1.  [1,null,2,3]  =>  [1,3,2]
 *
 *
 *
 *  Results:    AC (0 ms [100.00%]; 9.1 MB [95.00%])
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)  return result;

        solver(root, result);
        return result;      
    }

private:
    void solver(TreeNode* node, vector<int> &result) {
        if (node == NULL)   return;

        solver(node->left, result);
        result.push_back(node->val);
        solver(node->right, result);
    }
};