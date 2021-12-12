/*
 *  Results:    AC (20 ms [89.17%];  28 MB [42.15%])
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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

private:
    int dfs(const TreeNode* root) {
        if (root == NULL)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        int max_edge = 0, max_top = 0;
        max_edge = std::max((std::max(l, r) + root->val), root->val);
        max_top = std::max(max_edge, l+root->val+r);
        maxSum = std::max(maxSum, max_top);

        return max_edge;
    }

    int maxSum = INT_MIN;
};

