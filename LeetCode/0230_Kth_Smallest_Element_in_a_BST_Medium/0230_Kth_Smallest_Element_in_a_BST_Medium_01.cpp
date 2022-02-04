/*
 *  Results:    AC (12 ms [97.22%];  23.9 MB [98.47%])
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
    int kthSmallest(TreeNode* root, int k) {
        int layer = 0;

        res = 0;
        dfs(root, k, &layer);

        return res;
    }
private:
    void dfs(const TreeNode *node, const int k, int *layer) {
        if (!node)
            return;

        dfs(node->left, k, layer);

        *layer += 1;
        if (k == (*layer) && node)
            res = node->val;

        dfs(node->right, k, layer);
    }

    int res;
};

