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
 *  Results:    AC (48 ms [96.00%];  48.3 MB [78.58%])
 */


class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res = true;
        int goal_idx = nums.size()-1;

        if (goal_idx == 0)
            return true;

        for (int i = nums.size()-1; i >= 0; --i) {
            // distance to goal
            if (nums[i] < (goal_idx - i))
                res = false;
            else {
                res = true;
                goal_idx = i;
            }
        }

        return res;
    }
};
