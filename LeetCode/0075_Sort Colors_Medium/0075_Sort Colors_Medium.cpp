/**
 *  LeetCode: 75. Sort Colors (Medium)
 *
 *      Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 *      Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 *      Note: You are not suppose to use the library's sort function for this problem. A rather straight forward solution is a two-pass algorithm using counting sort.
 *
 *            First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 *            Could you come up with a one-pass algorithm using only constant space?
 *
 *
 *
 *      Example:    1.  [2,0,2,1,1,0] => [0,0,1,1,2,2]
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.5 MB [98.25%])
 */


class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)   return;

        int head = 0, rear = int(nums.size())-1;
        for (int i = 0; i <= rear; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[head++]);
            }
            if (nums[i] == 2) {
                swap(nums[i--], nums[rear--]);
            }
        }
    }
};