/**
 *  LeetCode: 55. Jump Game (Medium)
 *
 *     Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 *     Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.
 *
 *
 *
 *      Example:    1. [2,3,1,1,4] => true; (Jump 1 step from index 0 to 1, then 3 steps to the last index.)    
 *                  2. [3,2,1,0,4] => false; (You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.)
 *
 *
 *  Results:    AC (8 ms [96.90%];  9.8 MB [98.68%])
 */


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0)   return false;
        if (nums.size() == 1)   return true;
        
        int goalIdx = int(nums.size())-1, checkIdx = goalIdx-1;
        while (checkIdx >= 0) {
            if (nums[checkIdx] >= (goalIdx - checkIdx))
                goalIdx = checkIdx;

            checkIdx--;
        }

        if (goalIdx == 0)
            return true;
        else
            return false;
    }
};