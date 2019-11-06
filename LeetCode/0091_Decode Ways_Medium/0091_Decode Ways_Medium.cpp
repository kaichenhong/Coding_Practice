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
 *  Results:    AC (0 ms [100.00%];  8.5 MB [82.35%])
 */


class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }

        int dp_Size = int(s.size()) + 1;
        vector<int> dp_buff(dp_Size);
        dp_buff[0] = 1;
        dp_buff[1] = 1;

        for (size_t i = 1; i < s.size(); ++i) {
            int res = 0;
            if ('0' < s[i] && s[i] <= '9') {
                res += dp_buff[i];
                //printf("%d: %c ~ %d\n", i, s[i], res);
            }
            if (s[i-1] == '2' && '0' <= s[i] && s[i] <= '6' ||
                s[i-1] == '1' && '0' <= s[i] && s[i] <= '9' ) 
            {
                res += dp_buff[i-1];
                //printf("%d: %c%c ~~ %d\n", i, s[i-1], s[i], res);
            }
            dp_buff[i+1] = res;
        }

        return dp_buff.back();
    }
};