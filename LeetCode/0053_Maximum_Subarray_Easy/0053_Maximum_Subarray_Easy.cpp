/**
 *  LeetCode: 53. Maximum Subarray (Easy)
 *
 *      Given an integer array nums, find the continuous subarray (containing at least one number) which has the largest sum and return its sum.
 *
 *      Follow up:
 *
 *          If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 *
 *
 *      Example:    1. [-2,1,-3,4,-1,2,1,-5,4] => [4,-1,2,1] has the largest sum = 6;
 *
 *
 *
 *  Results:    AC (4 ms [98.63%];   9.1 MB [100.00%])
 */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)   return 0;
        if (nums.size() == 1)   return nums[0];

        /**
         *  Think:  
         *      How to "add/make" the maximum sum from the continuous subarray? What situation will the subarray have?
         *  
         *      add each element and check two situation.
         */
        int rear = 0, head = 0, sum = nums[0], maxSum = nums[0];
        for (int i = 1; i < int(nums.size()); ++i) {
            sum += nums[i];
            if (nums[i] > sum) {
                rear = i;
                sum = nums[i];
            }
            if (sum > maxSum) {
                head = i;
                maxSum = sum;
            }
        }
        return maxSum;
    }
};