/*
 *  Results:    AC (136 ms [90.52%];  86.2 MB [99.67%])
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
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return cnt;
    }
private:
    unsigned int cnt = 0;
    void dfs(const TreeNode *ptr, const int loc_max) {
        if (!ptr)
            return;

        if (ptr->val >= loc_max)
            cnt++;

        dfs(ptr->left, std::max(ptr->val, loc_max));
        dfs(ptr->right, std::max(ptr->val, loc_max));
    }
};

