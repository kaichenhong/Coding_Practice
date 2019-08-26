/**
 *  LeetCode: 26. Remove Duplicates from Sorted Array (Easy)
 *
 *      Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 *
 *      Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *
 *
 *      Example:    1. [1,1,2] => return length = 2, modified to [1,2] respectively;    
 *                  2. [0,0,1,1,1,2,2,3,3,4] => return length = 5, modified to [0,1,2,3,4] respectively;
 *
 *
 *  Results:    AC (16 ms [99.10%];   9.8 MB [97.50%])
 */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();
        
        // two pointer (index), slow (i) and fast (j). 
        // slow is point to unique number , fast is to search to next greater number.
        int i = 1;
        for (int j = 1; j < int(nums.size()); ++j) {
            if (nums[j] != nums[j-1]) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

/**
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)   return 0;
        if (nums.size() == 1)   return 1; 
        
        int *prev = &nums[0], *now;
        for (int i = 1; i < int(nums.size()); ++i) {
            now = &nums[i];
            if (*now == *prev) {
                continue;
            }
            else {
                prev++;
                *prev = *now;
            }
        }
        return (prev - &nums[0] + 1);
    }
};
 */