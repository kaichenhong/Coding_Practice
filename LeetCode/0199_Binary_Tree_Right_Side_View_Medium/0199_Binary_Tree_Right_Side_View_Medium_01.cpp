/*
 *  Results:    AC (0 ms [100.00%];  12 MB [68.29%])
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
        TreeNode *ptr = nullptr;

        if (!root)
            return res;

        q_buf.push(root);
        q_buf.push(nullptr); // for mark end of this tree level
        while (!q_buf.empty()) {
            if (q_buf.front() != nullptr) {
                ptr = q_buf.front();
                q_buf.pop();

                if (ptr->left)
                    q_buf.push(ptr->left);
                if (ptr->right)
                    q_buf.push(ptr->right);
            } else {
                res.push_back(ptr->val);
                q_buf.pop();
                if (!q_buf.empty())
                    q_buf.push(nullptr);
            }
        }

        return res;
    }
};

