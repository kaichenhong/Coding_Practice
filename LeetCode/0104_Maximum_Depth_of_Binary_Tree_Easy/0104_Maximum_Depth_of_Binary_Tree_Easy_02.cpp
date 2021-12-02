/**
 *  LeetCode: 104. Maximum Depth of Binary Tree (Easy)
 *
 *      Given a binary tree, find its maximum depth.
 *
 *      The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 *      Note: A leaf is a node with no children.
 *
 *
 *      Example:    binary tree [3,9,20,null,null,15,7] => return its depth = 3;
 *
 *                               3
 *                              / \
 *                             9  20
 *                               /  \
 *                              15   7
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];   19 MB [14.25%])
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
    int maxDepth(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> buf;

        if (!root)
            return res;

        buf.push(root);

        while (!buf.empty()) {
            res++;

            for (size_t i = buf.size(); i > 0; --i) {
                TreeNode *ptr = buf.front();

                if (ptr && ptr->left)
                    buf.push(ptr->left);
                if (ptr && ptr->right)
                    buf.push(ptr->right);

                buf.pop();
            }
        }

        return res;
    }
};
