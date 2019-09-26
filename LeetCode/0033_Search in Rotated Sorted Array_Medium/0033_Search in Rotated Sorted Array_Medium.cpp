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
 *  Results:    AC (0 ms [100.00%];  8.5 MB [100.00%])
 */


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)   return -1;
        if (nums.size() == 1)   return (nums[0] == target) ? 0 : -1;

        bool inOrdered = false;
        size_t l_Idx = 0, r_Idx = nums.size()-1;
        while (l_Idx < r_Idx) {
            //printf("%d, %d\n", nums[l_Idx], nums[r_Idx]);
            if (nums[l_Idx] == target)
                return l_Idx;
            if (nums[r_Idx] == target)
                return r_Idx;
            if (l_Idx == r_Idx-1)
                return -1;
            
            if (nums[l_Idx] < nums[r_Idx]) {
                inOrdered = true;
            }
            else {
                inOrdered = false;
            }

            size_t temp_Idx = (l_Idx + r_Idx) / 2;
            if (!inOrdered) {
                if (nums[l_Idx] < target && nums[r_Idx] < target ) {
                    r_Idx = temp_Idx;
                }
                else if (nums[l_Idx] > target && nums[r_Idx] > target) {
                    l_Idx = temp_Idx;
                }
                else {
                    break;
                }
            }
            else {
                if (nums[l_Idx] < target && target < nums[r_Idx]) {
                    if (nums[temp_Idx] < target) {
                        l_Idx = temp_Idx;
                    }
                    else if (nums[temp_Idx] > target) {
                        r_Idx = temp_Idx;
                    }
                    else if (nums[temp_Idx] == target) {
                        return temp_Idx;
                    }
                    else 
                        break;
                }
                else {
                    if (nums[l_Idx] > target && l_Idx > 0 && nums[l_Idx] > nums[l_Idx-1])
                        l_Idx--;
                    else if (nums[r_Idx] < target && r_Idx < nums.size()-1 && nums[r_Idx] < nums[r_Idx+1])
                        r_Idx++;
                    else
                        break;
                }
            }
        }
        return -1;
    }
};