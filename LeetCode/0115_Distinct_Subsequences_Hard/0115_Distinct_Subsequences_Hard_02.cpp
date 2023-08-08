/*
 *  Results:    AC (20 ms [96.25%];  6.33 MB [94.90%])
 */


class Solution {
public:
    int numDistinct(string s, string t) {
        const unsigned int rows = t.size(), cols = s.size();

        dp.resize(rows+1, 0);
        for (unsigned int c = 1; c <= cols; ++c) {
            unsigned int prev = 1;

            for (unsigned int r = 1; r <= rows; ++r) {
                unsigned int temp = dp[r];

                dp[r] = dp[r] + ((s[c-1] == t[r-1]) ? prev : 0);
                prev = temp;
            }
        }
        return dp[rows];
    }
private:
    vector<unsigned int> dp;
};

#if 0
class Solution {
public:
    int numDistinct(string s, string t) {
        const unsigned int rows = t.size(), cols = s.size();

        dp.resize(rows+1, vector<unsigned int>(cols+1, 0));
        for (unsigned int c = 0; c <= cols; ++c)
            dp[0][c] = 1;
        for (unsigned int c = 1; c <= cols; ++c)
            for (unsigned int r = 1; r <= rows; ++r)
                dp[r][c] = dp[r][c-1] + ((s[c-1] == t[r-1]) ? dp[r-1][c-1] : 0);
        return dp[rows][cols];
    }
private:
    vector<vector<unsigned int>> dp;
};
#endif

/*
   "  r  a  b  b  b  i  t
-------------------------
"  1  1  1  1  1  1  1  1
r  0  1  1  1  1  1  1  1
a  0  0  1  1  1  1  1  1
b  0  0  0  1  2  3  3  3
b  0  0  0  0  1  3  3  3
i  0  0  0  0  0  0  3  3
t  0  0  0  0  0  0  0  3

   "  b  a  b  g  b  a  g
-------------------------
"  1  1  1  1  1  1  1  1
b  0  1  1  2  2  3  3  3
a  0  0  1  1  1  1  4  4
g  0  0  0  0  1  1  1  5
*/

