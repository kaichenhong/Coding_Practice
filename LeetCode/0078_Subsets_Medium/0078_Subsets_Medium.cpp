/**
 *  LeetCode: 78. Subsets (Medium)
 *
 *      Given a set of distinct integers, nums, return all possible subsets (the power set).
 *
 *      Note: The solution set must not contain duplicate subsets.
 *
 *
 *
 *      Example:    1.  [1,2,3] => [ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], [] ]
 *
 *
 *
 *  Results:    AC (4 ms [97.65%];  9.1 MB [83.05%])
 */


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() == 0)   return results;

        size_t table = 0;
        for (size_t i = 0; i < pow(2, nums.size()); ++i) {
            vector<int> buffer;
            for (size_t j = 0; j < nums.size(); ++j) {
                if ((table >> j) & 1 == 1) {
                    buffer.push_back(nums[j]);
                }
            }
            results.push_back(buffer);
            table++;
        }

        return results;
    }
};