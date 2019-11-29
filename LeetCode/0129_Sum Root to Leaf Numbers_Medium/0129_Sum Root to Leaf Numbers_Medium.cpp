/**
 *  LeetCode: 129. Sum Root to Leaf Numbers (Medium)
 *
 *      Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 *      An example is the root-to-leaf path 1->2->3 which represents the number 123. Find the total sum of all root-to-leaf numbers.
 *
 *      Note: A leaf is a node with no children.
 *
 *
 *
 *      Example:    1.  [1,2,3]  =>  25;  (The root-to-leaf path 1->2 represents the number 12. The root-to-leaf path 1->3 represents the number 13. Therefore, sum = 12 + 13 = 25.)
 *                  2.  [4,9,0,5,1]  =>  1026;  (The root-to-leaf path 4->9->5 represents the number 495. The root-to-leaf path 4->9->1 represents the number 491. 
 *                                               The root-to-leaf path 4->0 represents the number 40. Therefore, sum = 495 + 491 + 40 = 1026.)
 *
 *
 *
 *  Results:    AC (0 ms [100.00%]; 12.3 MB [92.31%])
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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (root == nullptr)    return ans;

        backtracingSolver(root, ans);
        return ans;
    }

private:
    vector<int> buff;
    void backtracingSolver(TreeNode *node, int &ans) {
        if (node == NULL)   return;

        buff.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            size_t multipiler = 1;
            size_t sum = 0;
            for (int i = int(buff.size())-1; i >= 0; --i) {
                sum += buff[i] * multipiler;
                multipiler *= 10;
            }
            ans += sum;
        }
        backtracingSolver(node->left, ans);
        backtracingSolver(node->right, ans);
        buff.pop_back();
    }
};