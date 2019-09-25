/**
 *  LeetCode: 15. 3Sum (Medium)
 *
 *     Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 *     Note: The solution set must not contain duplicate triplets.
 *
 *
 *
 *      Example:    1. [-1, 0, 1, 2, -1, -4] => [ [-1, 0, 1], [-1, -1, 2] ];
 *
 *
 *  Results:    AC (92 ms [93.00%];  14.5 MB [100.00%])
 */


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        vector<vector<int>> results;

        if (nums.size() < 3)
            return results;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size()-2; ++i) {
            // To avoid duplicates, never let Idx refer to the same value twice (in an output).
            if (i != 0 && nums[i] == nums[i-1]) 
                continue;

            size_t leftIdx = i+1, rightIdx = nums.size()-1;
            while (leftIdx < rightIdx) {
                int sum = nums[leftIdx] + nums[i] + nums[rightIdx];

                if (sum < 0) {
                    leftIdx++;
                }
                else if (sum > 0) {
                    rightIdx--;
                }
                else {
                    results.push_back(vector<int>{nums[i], nums[leftIdx], nums[rightIdx]});
                    leftIdx++;
                    rightIdx--;

                    // To avoid duplicates, never let Idx refer to the same value twice (in an output).
                    while (leftIdx < rightIdx && nums[leftIdx] == nums[leftIdx-1]) 
                        leftIdx++;
                    while (leftIdx < rightIdx && nums[rightIdx] == nums[rightIdx+1]) 
                        rightIdx--;
                }
            }
        }
        return results;
    }
};