/**
 *  LeetCode: 102. Binary Tree Level Order Traversal (Medium)
 *
 *      Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 *
 *
 *      Example:    1.  [3,9,20,null,null,15,7]  =>  [ [3], [9,20], [15,7] ]
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  13.8 MB [98.59%])
 *              AC (4 ms [93.41%];  14.5 MB [21.12%])
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)   return result;

        queue<TreeNode*> buff;
        buff.push(root);
        while (!buff.empty()) {
            size_t buff_size = buff.size();
            vector<int> vec(buff_size);
            for (size_t i = 0; i < buff_size; ++i) {
                TreeNode *temp = buff.front();
                vec[i] = temp->val;
                if (temp->left != NULL)   buff.push(temp->left);
                if (temp->right != NULL)   buff.push(temp->right);
                buff.pop();
            }
            result.push_back(vec);
        }

        return result;
    }
};

/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)   return result;

        solver(root, 0, result);

        for (size_t i = 0; i < result.size(); ++i) {
            result[i].resize(result[i].size());
        }
        return result;
    }

private:
    void solver(TreeNode *node, int level, vector<vector<int>> &result) {
        if (node == NULL)   return;
        if (result.size() < level + 1) 
            result.resize(level + 1);

        result[level].push_back(node->val);
		solver(node->left, level + 1, result);
        solver(node->right, level + 1, result);
    }
};*/