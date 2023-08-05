/*
 *  Results:    AC (4 ms [97.10%];  9.2 MB [26.45%])
 */


class Solution {
public:
    int minDistance(string word1, string word2) {
        const unsigned int rows = word2.size(), cols = word1.size();

        init_dp_data(rows, cols);
        for (unsigned int j = 1; j <= rows; ++j) {
            for (unsigned int i = 1; i <= cols; ++i) {
                dp[j][i] = (word1[i-1] == word2[j-1])
                    ? (dp[j-1][i-1])
                    : (min(dp[j-1][i-1], min(dp[j-1][i], dp[j][i-1])) + 1);
                // printf("dp[%u][%u] = %u\n", j, i, dp.at(j).at(i));
            }
        }
        return dp[rows][cols];
    }
private:
    inline void init_dp_data(const unsigned int rows, const unsigned int cols) {
        dp.resize(rows + 1, vector<unsigned int>(cols + 1));
        for (unsigned int i = 1; i <= cols; ++i)
            dp[0][i] = i;
        for (unsigned int j = 1; j <= rows; ++j)
            dp[j][0] = j;
    }
    vector<vector<unsigned int>> dp;
};


/*
   "  h  o  r  s  e
-------------------
"  0  1  2  3  4  5
r  1  1  2  2  3  4
o  2  2  1  2  3  4
s  3  3  2  2  2  3
*/

