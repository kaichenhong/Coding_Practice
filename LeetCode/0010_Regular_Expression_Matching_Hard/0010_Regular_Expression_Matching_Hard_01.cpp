/*
 *  Results:    AC (0 ms [100.00%];  6.0 MB [99.29%])
 */


class Solution {
public:
    bool isMatch(string s, string p) {
        const unsigned int len_s = s.size(), len_p = p.size();

        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for (int i = 1; i <= len_p; ++i) {
            // printf("%2d|%c| ", i, p[i-1]);
            for (int j = 0; j <= len_s; ++j) {
                if (p[i-1] == '*')
                    dp[i][j] =
                        (i >= 2) && dp[i-2][j] ||
                        (j >= 1) && ((s[j-1] == p[i-2]) || (p[i-2] == '.')) &&
                        dp[i][j-1];
                else
                    dp[i][j] = (j >= 1) && dp[i-1][j-1] && ((s[j-1] == p[i-1]) || (p[i-1] == '.'));

                // printf("%u  ", dp[i][j]);
            }
            // printf("\n");
        }

        return dp[len_p][len_s];
    }
private:
    // s.length <= 20 && p.length <= 20
    bool dp[21][21];
};

/*
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
   "  a  a  b
-------------
"  1  0  0  0
c  0  0  0  0
*  1  0  0  0
a  0  1  0  0
*  1  1  1  0
b  0  0  0  1


s = "aaa"
p = "ab*ac*a"
Output: true
   "  a  a  a
-------------
"  1  0  0  0
a  0  1  0  0
b  0  0  0  0
*  0  1  0  0
a  0  0  1  0
c  0  0  0  0
*  0  0  1  0
a  0  0  0  1


s = "mississippi"
p = "mis*is*p*."
Output: false
      0  1  2  3  4  5  6  7  8  9  0  1
      "  m  i  s  s  i  s  s  i  p  p  i
----------------------------------------
 1|m| 0  1  0  0  0  0  0  0  0  0  0  0
 2|i| 0  0  1  0  0  0  0  0  0  0  0  0
 3|s| 0  0  0  1  0  0  0  0  0  0  0  0
 4|*| 0  0  1  1  1  0  1  1  0  0  0  0
 5|i| 0  0  0  0  0  1  0  0  1  0  0  0
 6|s| 0  0  0  0  0  0  1  0  0  0  0  0
 7|*| 0  0  0  1  1  1  1  1  1  0  0  0
 8|p| 0  0  0  0  0  0  0  0  0  1  0  0
 9|*| 0  0  0  1  1  1  1  1  1  1  1  0
10|.| 0  0  0  0  1  1  1  1  1  1  1  1
*/

