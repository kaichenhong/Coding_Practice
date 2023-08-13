/*
 *  Results:    AC (78 ms [100.00%];  8.12 MB [98.48%])
 */


#if 1
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const unsigned int n = nums.size();

        init_dp_data(nums, n);
        for (int r_bound = 1; r_bound < n; ++r_bound) {
            for (int l_bound = (r_bound - 1); l_bound >= 0; --l_bound) {
                const int l_val = (l_bound <= 0) ? 1 : nums[l_bound-1];
                const int r_val = (r_bound >= (n-1)) ? 1 : nums[r_bound+1];

                for (int k = l_bound; k <= r_bound; ++k) {
                    const unsigned int l_dp = (k <= 0) ? 0 : dp[l_bound][k-1];
                    const unsigned int r_dp = (k >= (n-1)) ? 0 : dp[k+1][r_bound];

                    dp[l_bound][r_bound] =
                        max(dp[l_bound][r_bound], l_dp + (l_val * nums[k] * r_val) + r_dp);
                }
            }
        }
        return dp[0][n-1];
    }
private:
    inline void init_dp_data(const vector<int> &nums, const unsigned int n) {
        // dp.resize(n, vector<unsigned int>(n, 0));

        dp[0][0] = 1 * nums[0] * ((n > 1) ? nums[1] : 1);
        for (unsigned int i = 1; i < (n - 1); ++i)
            dp[i][i] = nums[i-1] * nums[i] * nums[i+1];
        dp[n-1][n-1] = ((n > 1) ? nums[n-2] : 1) * nums[n-1] * 1;
    }
    // vector<vector<unsigned int>> dp;
    // array<array<unsigned int, 300>, 300> dp;
    unsigned int dp[300][300];
};
#else
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const unsigned int n = nums.size();

        dp.resize(n, vector<unsigned int>(n, 0));
        for (unsigned int win_size = 1; win_size <= n; ++win_size) {
            for (int l_bound = 0; l_bound < (n - win_size + 1); ++l_bound) {
                const int r_bound = l_bound + (win_size - 1);
                const int l_val = (l_bound <= 0) ? 1 : nums[l_bound-1];
                const int r_val = (r_bound >= (n-1)) ? 1 : nums[r_bound+1];

                for (int k = l_bound; k <= r_bound; ++k) {
                    const unsigned int l_dp = (k <= 0) ? 0 : dp[l_bound][k-1];
                    const unsigned int r_dp = (k >= (n-1)) ? 0 : dp[k+1][r_bound];

                    dp[l_bound][r_bound] =
                        max(dp[l_bound][r_bound], l_dp + (l_val * nums[k] * r_val) + r_dp);
                }
            }
        }
        return dp[0][n-1];
    }
private:
    vector<vector<unsigned int>> dp;
};
#endif

/*
l_bound / r_bound
    0    1    2    3
--------------------
0|  3   30  159  167
1|  0   15  135  159
2|  0    0   40   48
3|  0    0    0   40
*/

