/*
 *  Results:    AC (0 ms [100.00%];  12.0 MB [68.29%])
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> q_buf;

        if (!root)
            return res;

        q_buf.push(root);
        while (!q_buf.empty()) {
            const unsigned int n = q_buf.size();
            TreeNode *ptr = nullptr;

            /* go through all nodes of this level */
            for (unsigned int i = 0; i < n; ++i) {
                ptr = q_buf.front();
                q_buf.pop();

                if (ptr->left)
                    q_buf.push(ptr->left);
                if (ptr->right)
                    q_buf.push(ptr->right);
            }

            if (ptr)
                res.push_back(ptr->val);
        }

        return res;
    }
};

