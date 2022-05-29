/*
 *  Results:    AC (19 ms [83.12%];  25.8 MB [93.23%])
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return builder(preorder, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* builder(const vector<int> &preorder, const vector<int> &inorder, const int in_start, const int in_end) {
        TreeNode *ptr = nullptr;
        unsigned int target = 0;

        if (in_start > in_end)
            return nullptr;

        ptr = new TreeNode(preorder[idx++]);
        for (unsigned int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == ptr->val) {
                target = i;
                break;
            }
        }

        ptr->left = builder(preorder, inorder, in_start, target-1);
        ptr->right = builder(preorder, inorder, target+1, in_end);

        return ptr;
    }
    /* preorder index */
    unsigned int idx = 0;
};

