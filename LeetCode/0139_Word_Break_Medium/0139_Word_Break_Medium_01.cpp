/*
 *  Results:    AC (8 ms [69.49%];  14.6 MB [23.12%])
 */


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> table(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);

        dp[0] = true;
        for (int i = 0; i < s.size()+1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (table.count(s.substr(j, i-j)) && dp[j])
                    dp[i] = true;
            }
        }

        return dp[s.size()];
    }
};

