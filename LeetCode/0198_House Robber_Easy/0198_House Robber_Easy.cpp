/**
 *  LeetCode: 198. House Robber (Easy)
 *
 *      Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *      (It will automatically contact the police if two adjacent houses were broken into on the same night.)
 *
 *
 *      Example:    1. [1,2,3,1] => 4.
 *                  Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount you can rob = 1 + 3 = 4.
 *
 *                  2. [2,7,9,3,1] => 12.
 *                  Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1). Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.4 MB [100.00%])
 */


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return nums[0];

        // When total amount house is 1, the result is; and total is 2, result...; and 3, results...; DP;
        int first = nums[0], second = max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); ++i) {
            int buf = max(nums[i] + first, second);
            first = second;
            second = buf;
        }
        return second;
    }
};