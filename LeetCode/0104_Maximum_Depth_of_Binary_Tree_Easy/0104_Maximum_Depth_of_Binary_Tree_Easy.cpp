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
 *  Results:    AC (4 ms [98.10%];   19.1 MB [97.80%])
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
void treeDepthTravel(TreeNode* node, int depth, int &maxDepth) 
{
    depth++;
    if (node == NULL) {
        if (depth > maxDepth)   
            maxDepth = depth-1;
        return;
    }

    treeDepthTravel(node->left, depth, maxDepth);
    treeDepthTravel(node->right, depth, maxDepth);
}


class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0, maxDepth = 0;
        // tree traversal, make good use of function call back (and call by value, call by reference).
        treeDepthTravel(root, depth, maxDepth);

        return maxDepth;
    }
};