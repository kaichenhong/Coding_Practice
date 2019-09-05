/**
 *  LeetCode: 167. Two Sum II - Input array is sorted (Easy)
 *
 *      Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 *
 *      The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 *      
 *      Note:   Your returned answers (both index1 and index2) are not zero-based.
 *              You may assume that each input would have exactly one solution and you may not use the same element twice.
 *
 *
 *      Example:    numbers = [2,7,11,15], target = 9 => [1,2]
 *
 *
 *
 *  Results:    AC (4 ms [97.01%];  9.3 MB [100.00%])
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = int(numbers.size());
        if (size == 2)
            return vector<int>{1, 2};

        // two pointers (idx), add there sum and compare target to find out how to move pointers.
        int leftIdx = 0, rightIdx = size-1;
        vector<int> idx(2);
        while (true) {
            int sum = numbers[leftIdx] + numbers[rightIdx];
            if (sum > target) {
                rightIdx--;
            }
            if (sum < target) {
                leftIdx++;
            }

            if (sum == target) {
                idx[0] = leftIdx+1;
                idx[1] = rightIdx+1;
                break;
            }
        }
        return idx;
    }
};