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
 *  Results:    AC (0 ms [100.00%];  7.9 MB [20.74%])
 */


class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1);

        dp[0] = 0;
        dp[1] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
            dp[i+1] = std::max(dp[i-1]+nums[i], dp[i]);

        return dp[nums.size()];
    }
};

