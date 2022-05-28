/*
 *  Results:    AC (8 ms [93.55%];  21.7 MB [33.67%])
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
    bool isValidBST(TreeNode* root) {
        in_order_traversal(root);
        for (unsigned int i = 0; i < in_order.size()-1; ++i)
            if (in_order[i] >= in_order[i+1])
                return false;
        return true;
    }
private:
    vector<int> in_order;
    void in_order_traversal(const TreeNode *ptr) {
        if (!ptr)
            return;

        in_order_traversal(ptr->left);
        in_order.push_back(ptr->val);
        in_order_traversal(ptr->right);
    }
};

