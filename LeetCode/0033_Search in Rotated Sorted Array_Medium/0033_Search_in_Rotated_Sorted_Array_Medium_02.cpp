/**
 *  LeetCode: 33. Search in Rotated Sorted Array (Medium)
 *
 *     Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 *     (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]). You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 *     Note: You may assume no duplicate exists in the array. Your algorithm's runtime complexity must be in the order of O(log n).
 *
 *
 *
 *      Example:    1. nums = [4,5,6,7,0,1,2], target = 0 => 4;
 *                  2. nums = [4,5,6,7,0,1,2], target = 3 => -1;
 *
 *
 *  Results:    AC (0 ms [100.00%];  11 MB [74.53%])
 */


int find_target(int target, int l, int r, vector<int> &nums) {
    if (l > r)
        return -1;
    if (nums[(l+r)/2] == target)
        return (l+r)/2;
    if (nums[l] == target)
        return l;
    if (nums[r] == target)
        return r;

    /* clip out the interval/direction */
    if (nums[(l+r)/2] < nums[r]) {
        if (nums[(l+r)/2] < target && target < nums[r])
            return find_target(target, (l+r)/2, r-1, nums);
        else
            return find_target(target, l+1, (l+r)/2, nums);
    } else {
        if (nums[l] < target && target < nums[(l+r)/2])
            return find_target(target, l+1, (l+r)/2, nums);
        else
            return find_target(target, (l+r)/2, r-1, nums);
    }
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return find_target(target, 0, nums.size()-1, nums);
    }
};
