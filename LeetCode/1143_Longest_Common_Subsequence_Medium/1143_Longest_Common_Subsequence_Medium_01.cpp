/*
 *  Results:    AC (24 ms [78.82%];  12.9 MB [59.30%])
 */


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const size_t len1 = text1.length();
        const size_t len2 = text2.length();
        vector<vector<unsigned int>> dp(len1+1, vector<unsigned int>(len2+1, 0));

        for (size_t i = 1; i < len1 + 1; ++i) {
            for (size_t j = 1; j < len2 + 1; ++j) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[len1][len2];
    }
};

