/*
 *  Results:    AC (18 ms [48.96%];  7.7 MB [49.97%])
 */


class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i = s.size()-1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if ((s[i] == s[j]) && ((j-i) <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }

        return res;
    }
};

