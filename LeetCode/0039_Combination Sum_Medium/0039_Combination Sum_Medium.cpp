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
 *  Results:    AC (8 ms [98.31%];  9.6 MB [63.89%])
 */


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) 
            return results;
        
        sort(candidates.begin(), candidates.end());
        solver(candidates, target, 0, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> temp;
    void solver(vector<int>& candidates, int &target, int searchHead, int sum) {        
        for (size_t i = searchHead; i < candidates.size(); ++i) {
            temp.push_back(candidates[i]);

            int curSum = sum + candidates[i];
            if (curSum < target) {
                solver(candidates, target, i, curSum);
            }
            else if (curSum > target) {
                temp.pop_back();
                return;
            }
            else {  // curSum == target
                results.push_back(temp);
                
                temp.pop_back();
                return;
            }

            temp.pop_back();
        }
    }
};