/**
 *  LeetCode: 40. Combination Sum II (Medium)
 *
 *     Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 *
 *     Each number in candidates may only be used once in the combination.
 * 
 *     Note: All numbers (including target) will be positive integers. The solution set must not contain duplicate combinations.
 *
 *
 *
 *      Example:    1. candidates = [10,1,2,7,6,1,5], target = 8 => A solution set is: [ [1, 7], [1, 2, 5], [2, 6], [1, 1, 6] ];
 *                  2. candidates = [2,5,2,1,2], target = 5 => A solution set is: [ [1,2,2], [5] ];
 *
 *
 *  Results:    AC (4 ms [98.86%];  9.1 MB [84.21%])
 */


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0)     return results;

        sort(candidates.begin(), candidates.end());
        solver(candidates, target, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> temp;
    void solver(vector<int>& candidates, int target, int idx) {
        for (size_t i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i-1])    continue;

            //int subTarget = target-candidates[i];
            if (target-candidates[i] < 0) 
                return;

            temp.push_back(candidates[i]);
            if (target-candidates[i] == 0) {
                results.push_back(temp);
                temp.pop_back();
                return;
            }
            else 
                solver(candidates, target-candidates[i], i+1);
            temp.pop_back();
        }
    }
};