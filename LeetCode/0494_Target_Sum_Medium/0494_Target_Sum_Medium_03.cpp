/*
 *  Results:    AC (177 ms [41.26%];  47.1 MB [16.30%])
 */


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size() + 1);
        dp.at(0)[0] = 1;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            for (const auto &iter : dp.at(i)) {
                const int sum = iter.first;
                const int cnt = iter.second;

                dp.at(i+1)[sum + nums.at(i)] += cnt;
                dp.at(i+1)[sum - nums.at(i)] += cnt;
                // printf("dp[%u][%d] = %d, => dp[%u][%d] = %d, dp[%u][%d] = %d\n",
                //    i, sum, dp.at(i)[sum],
                //    i+1, sum + nums.at(i), dp.at(i+1)[sum + nums.at(i)],
                //    i+1, sum - nums.at(i), dp.at(i+1)[sum - nums.at(i)]);
            }
        }
        return dp.at(nums.size())[target];
    }
private:
    vector<unordered_map<int, unsigned int>> dp;
};

/*
dp[0][0] = 1, => dp[1][1] = 1, dp[1][-1] = 1
dp[1][-1] = 1, => dp[2][0] = 1, dp[2][-2] = 1
dp[1][1] = 1, => dp[2][2] = 1, dp[2][0] = 2
dp[2][2] = 1, => dp[3][3] = 1, dp[3][1] = 1
dp[2][-2] = 1, => dp[3][-1] = 1, dp[3][-3] = 1
dp[2][0] = 2, => dp[3][1] = 3, dp[3][-1] = 3
dp[3][-3] = 1, => dp[4][-2] = 1, dp[4][-4] = 1
dp[3][-1] = 3, => dp[4][0] = 3, dp[4][-2] = 4
dp[3][1] = 3, => dp[4][2] = 3, dp[4][0] = 6
dp[3][3] = 1, => dp[4][4] = 1, dp[4][2] = 4
dp[4][4] = 1, => dp[5][5] = 1, dp[5][3] = 1
dp[4][2] = 4, => dp[5][3] = 5, dp[5][1] = 4
dp[4][0] = 6, => dp[5][1] = 10, dp[5][-1] = 6
dp[4][-4] = 1, => dp[5][-3] = 1, dp[5][-5] = 1
dp[4][-2] = 4, => dp[5][-1] = 10, dp[5][-3] = 5

memo[4][4] = 1
memo[4][2] = 1
memo[3][3] = 2
memo[4][0] = 0
memo[3][1] = 1
memo[2][2] = 3
memo[4][-2] = 0
memo[3][-1] = 0
memo[2][0] = 1
memo[1][1] = 4
memo[4][-4] = 0
memo[3][-3] = 0
memo[2][-2] = 0
memo[1][-1] = 1
memo[0][0] = 5

memo[4][7] = 0
memo[4][5] = 0
memo[3][6] = 0
memo[4][3] = 0
memo[3][4] = 0
memo[2][5] = 0
memo[4][1] = 1
memo[3][2] = 1
memo[2][3] = 1
memo[1][4] = 1
memo[4][-1] = 1
memo[3][0] = 2
memo[2][1] = 3
memo[1][2] = 4
memo[0][3] = 5
*/

