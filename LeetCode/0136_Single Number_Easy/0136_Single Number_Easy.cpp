/**
 *  LeetCode: 136. Single Number (Easy)
 *
 *      Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *
 *      Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 *
 *      Example:    1. [2,2,1] => 1;    2. [4,1,2,1,2] => 4;
 *
 *
 *
 *  Results:    AC (12 ms [96.13%];  9.6 MB [100.00%])
 */


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = int(nums.size());
        if (size == 1)  return nums[0];
        
        // Think the property of the "XOR".
        int single = nums[0];
        for (int i = 1; i < size; ++i) {
            single ^= nums[i];
        }
        return single;
    }
};