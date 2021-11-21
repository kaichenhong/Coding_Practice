/**
 *  LeetCode: 91. Decode Ways (Medium)
 *
 *     A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 *     'A' -> 1
 *     'B' -> 2
 *     ...
 *     'Z' -> 26
 *
 *     Given a non-empty string containing only digits, determine the total number of ways to decode it.
 *
 *
 *
 *      Example:    1. "12" => 2;   It could be decoded as "AB" (1 2) or "L" (12).
 *                  2. "226" => 3;  It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 *
 *
 *  Results:    AC (0 ms [100.00%];  6.2 MB [41.73%]);  (DP)
 */


class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+2, 0);

        dp[0] = 1;
        dp[1] = 1;
        for (size_t i = 0; i < s.size(); ++i) {
            if (std::stoi(s.substr(i, 1)) >= 1 && std::stoi(s.substr(i, 1)) <= 9)
                dp[i+2] += dp[i+1];
            if (i > 0 && std::stoi(s.substr(i-1, 2)) >= 10 && std::stoi(s.substr(i-1, 2)) <= 26)
                dp[i+2] += dp[i];
        }

        return dp[s.size()+1];
    }
};

