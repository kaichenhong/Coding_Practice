/*
 *  Results:    AC (11 ms [88.05%];  9.3 MB [63.30%])
 */


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int total_sum = accumulate(nums.begin(), nums.end(), 0);
        const int new_target = (total_sum + target) / 2;

        if ((target + total_sum < 0) || ((total_sum + target) % 2))
            return 0;

        dp.resize(new_target + 1);
        dp.at(0) = 1;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            // printf("index:%u", i);
            for (int j = new_target; j >= nums.at(i); --j) {
                dp.at(j) += dp.at(j - nums.at(i));
                // printf(" => dp[%u]:%d(dp[%u]:%d)",
                //    j, dp.at(j), j - nums.at(i), dp.at(j - nums.at(i)));
            }
            // printf("\n");
        }

        return dp.at(new_target);
    }
private:
    vector<int> dp;
};

/*
dp| 0  1  2  3  4
-----------------
  | 1
0 |    1  0  0  0
1 |    2  1  0  0
2 |    3  3  1  0
3 |    4  6  4  1
4 |    5 10 10  5

index:0 => dp[4]:0(dp[3]:0) => dp[3]:0(dp[2]:0) => dp[2]:0(dp[1]:0) => dp[1]:1(dp[0]:1)
index:1 => dp[4]:0(dp[3]:0) => dp[3]:0(dp[2]:0) => dp[2]:1(dp[1]:1) => dp[1]:2(dp[0]:1)
index:2 => dp[4]:0(dp[3]:0) => dp[3]:1(dp[2]:1) => dp[2]:3(dp[1]:2) => dp[1]:3(dp[0]:1)
index:3 => dp[4]:1(dp[3]:1) => dp[3]:4(dp[2]:3) => dp[2]:6(dp[1]:3) => dp[1]:4(dp[0]:1)
index:4 => dp[4]:5(dp[3]:4) => dp[3]:10(dp[2]:6) => dp[2]:10(dp[1]:4) => dp[1]:5(dp[0]:1)
*/

