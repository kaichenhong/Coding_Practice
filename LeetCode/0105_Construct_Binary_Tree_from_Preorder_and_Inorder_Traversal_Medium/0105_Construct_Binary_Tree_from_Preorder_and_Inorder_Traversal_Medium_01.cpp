/*
 *  Results:    AC (4 ms [99.90%];  26.3 MB [45.47%])
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
        if (preorder.size() == 0)
            return NULL;

        if (preorder.size() == 1)
            return new TreeNode(preorder[0]);


        for (size_t i = 0; i < preorder.size(); ++i)
            map[inorder[i]] = i;

        return build(preorder, 0, preorder.size()-1, inorder, 0, preorder.size()-1);
    }

private:
    TreeNode* build(const vector<int>& preorder, int ph, int pe, const vector<int>& inorder, int ih, int ie) {
        if (ph > pe || ih > ie)
            return NULL;

        int im = map[preorder[ph]];
        int pm = ph+(map[preorder[ph]]-ih);

        TreeNode *root = new TreeNode(preorder[ph]);
        root->left = build(preorder, ph+1, pm, inorder, ih, im-1);
        root->right = build(preorder, pm+1, pe, inorder, im+1, ie);

        return root;
    }

    unordered_map<int, int> map;
};

