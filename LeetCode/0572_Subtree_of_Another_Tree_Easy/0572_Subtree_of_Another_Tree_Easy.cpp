/*
 *  Results:    AC (20 ms [92.97%];  28.8 MB [56.62%])
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return true;
        if (!root)
            return false;

        if (dfs(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot)
            || isSubtree(root->right, subRoot);
    }

private:
    bool dfs(TreeNode *ptr, TreeNode *sub_ptr) {
        if (!ptr && !sub_ptr)
            return true;
        if (!ptr || !sub_ptr)
            return false;

        return (ptr->val == sub_ptr->val)
            && dfs(ptr->left, sub_ptr->left)
            && dfs(ptr->right, sub_ptr->right);
    }
};

