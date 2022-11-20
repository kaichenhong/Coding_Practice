/*
 *  Results:    AC (17 ms [86.86%];  6.3 MB [98.22%])
 */


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const size_t len1 = text1.length();
        const size_t len2 = text2.length();
        vector<unsigned int> dp(len2+1, 0);
        vector<unsigned int> dp_curr(len2+1, 0);

        for (size_t i = 1; i < len1 + 1; ++i) {
            for (size_t j = 1; j < len2 + 1; ++j) {
                if (text1[i-1] == text2[j-1])
                    dp_curr[j] = dp[j-1] + 1;
                    // dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp_curr[j] = std::max(dp_curr[j-1], dp[j]);
                    // dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }

            dp = dp_curr;
        }

        return dp[len2];
    }
};

