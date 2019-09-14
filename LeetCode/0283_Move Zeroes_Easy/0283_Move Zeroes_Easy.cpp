/**
 *  LeetCode: 283. Move Zeroes (Easy)
 *
 *      Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 *      You must do this in-place without making a copy of the array. Minimize the total number of operations.
 *
 *
 *      Example:    1. [0,1,0,3,12] => [1,3,12,0,0];   6 = 2 × 3.
 *
 *
 *
 *  Results:    AC (12 ms [96.61%];  9.4 MB [100.00%])
 */


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // speed up cin/cout.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        unsigned int countZeros = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                countZeros++;
            }
            else if (countZeros > 0) {
                nums[i - countZeros] = nums[i];
                nums[i] = 0;
            }
        }
    }
};