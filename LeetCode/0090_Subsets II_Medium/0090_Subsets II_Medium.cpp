/**
 *  LeetCode: 90. Subsets II (Medium)
 *
 *      Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 *
 *      Note: The solution set must not contain duplicate subsets.
 *
 *
 *
 *      Example:    1.  [1,2,2]  =>  [ [2], [1], [1,2,2], [2,2], [1,2], [] ]
 *
 *
 *
 *  Results:    AC (4 ms [99.56%];  9.2 MB [100.00%])
 */


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() == 0)   return results;

        sort(nums.begin(), nums.end());
        results.push_back(vector<int>());
        size_t prev_size = 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            size_t curr_size = results.size();
            for (size_t j = 0; j < curr_size; ++j) {
                if (i > 0 && nums[i-1] == nums[i] && j < prev_size)
                    continue;
                
                results.push_back(results[j]);
                results.back().push_back(nums[i]);
            }

            if (results.back().size() == nums.size()) break;
            prev_size = curr_size;
        }

        return results;
    }
};


/*
Input
[1,1,2,2]
Output
[[],[1],[1,1],[1,1,2],[1,1,2,2],[1,2],[1,2,2],[2],[2,2]]

[[],
 [1],
 [1],[1,1],
 [2],[1,2],[1,2],[1,1,2],
 [2],[1,2],[1,2],[1,1,2],[2,2],[1,2,2],[1,2,2],[1,1,2,2]]

[[],
 [1],
 [1,1],
 [2],[1,2],[1,1,2],
 [2,2],[1,2,2],[1,1,2,2]]
*/