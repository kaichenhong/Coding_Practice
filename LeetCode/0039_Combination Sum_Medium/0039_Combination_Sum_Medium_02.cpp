/**
 *  LeetCode: 39. Combination Sum (Medium)
 *
 *     Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 *
 *     The same repeated number may be chosen from candidates unlimited number of times.
 *
 *     Note: All numbers (including target) will be positive integers. The solution set must not contain duplicate combinations.
 *
 *
 *
 *      Example:    1. candidates = [2,3,6,7], target = 7 => A solution set is: [ [7], [2,2,3] ];
 *                  2. candidates = [2,3,5], target = 8 => A solution set is: [ [2,2,2,2], [2,3,3], [3,5] ];
 *
 *
 *  Results:    AC (4 ms [93.24%];  10.7 MB [89.30%])
 */


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;

        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, sub, res);

        return res;
    }

private:
    /* think how to divide the target to each candidate */
    // 7
    // 2 3 6 7
    //
    // 5 4 1 0
    // 3 1
    // 1
    void dfs(vector<int> &candidates, int target, unsigned int idx, vector<int> &sub, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }

        for (unsigned int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target)
                break;

            sub.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, sub, res);
            sub.pop_back();
        }
    }
};

