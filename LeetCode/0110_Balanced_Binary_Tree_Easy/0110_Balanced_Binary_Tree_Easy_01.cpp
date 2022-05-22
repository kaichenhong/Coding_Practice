/*
 *  Results:    AC (0 ms [100.00%];  20.7 MB [95.57%])
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
    bool isBalanced(TreeNode* root) {
        return (dfs(root) != -1) ? true : false;
    }
private:
    int dfs(const TreeNode *ptr) {
        int l_len = 0, r_len = 0;

        if (!ptr)
            return 0;

        l_len = dfs(ptr->left);
        if (l_len == -1)
            return -1;
        r_len = dfs(ptr->right);
        if (r_len == -1)
            return -1;

        if (abs(l_len - r_len) > 1)
            return -1;

        return max(l_len, r_len) + 1;
    }
};

