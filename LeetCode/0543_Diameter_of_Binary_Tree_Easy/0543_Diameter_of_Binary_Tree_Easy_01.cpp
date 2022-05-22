/*
 *  Results:    AC (7 ms [93.58%];  20.2 MB [93.00%])
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
    int diameterOfBinaryTree(TreeNode* root) {
        max_length = 0;
        dfs(root);
        return max_length;
    }

private:
    int dfs(const TreeNode *ptr) {
        int l_length = 0, r_length = 0;

        if (!ptr)
            return 0;

        l_length = dfs(ptr->left);
        r_length = dfs(ptr->right);

        max_length = std::max(max_length, (l_length + r_length));
        return std::max(l_length, r_length) + 1;
    }

    int max_length;
};

