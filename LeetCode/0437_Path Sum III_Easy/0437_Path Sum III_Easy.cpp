/**
 *  LeetCode: 437. Path Sum III (Easy)
 *
 *      You are given a binary tree in which each node contains an integer value.
 *
 *      Find the number of paths that sum to a given value.
 *
 *      The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
 *
 *      The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000. 
 *
 *
 *      Example:    root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 *                            10
 *                           /  \
 *                          5   -3
 *                         / \    \
 *                        3   2   11
 *                       / \   \
 *                      3  -2   1
 *
 *                  Return 3. The paths that sum to 8 are:
 *
 *                  1.  5 -> 3
 *                  2.  5 -> 2 -> 1
 *                  3. -3 -> 11
 *
 *
 *
 *  Results:    AC (24 ms [56.15%];  15 MB [32.26%])
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
    int pathSum(TreeNode* root, int sum) {
        sumMap.resize(1001);
        deep = -1;
        cnt = 0;

        PathSum(root, sum);
        return cnt;
    }

private:
    int PathSum(TreeNode* root, int &sum) 
    {
        deep++;
        if (root == NULL) {
            deep--;
            return 0;
        }

        if (root->val == sum)   
            cnt++;

        if (sumMap.size() == 0) {
            sumMap[0] = root->val;
        }
        else {
            for (size_t i = 0; i < deep; ++i) {
                sumMap[i] += root->val;
                if (sumMap[i] == sum) {
                    cnt++;
                }
            }
            sumMap[deep] = root->val;
        }

        PathSum(root->left, sum);
        PathSum(root->right, sum);
        for (size_t i = 0; i < deep; ++i) {
            sumMap[i] -= root->val;
        }
        sumMap[deep] = 0;

        deep--;
        return cnt;
    }

    vector<int> sumMap;
    int deep;
    int cnt;
};