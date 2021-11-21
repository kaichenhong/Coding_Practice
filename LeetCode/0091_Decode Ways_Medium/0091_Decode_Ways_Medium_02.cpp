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
 *  Results:    AC (4 ms [27.80%];  8.3 MB [6.95%]);  (DFS + records)
 */


class Solution {
public:
    int numDecodings(string s) {
        return dfs(s);
    }

private:
    int dfs(const string &s) {
        if (s.size() == 0)
            return 1;
        if (s[0] == '0')
            return 0;

        if (map.count(s))
            return map[s];

        int res = dfs(s.substr(1));

        if (s.size() >= 2) {
            if (std::stoi(s.substr(0, 2)) <= 26)
                res += dfs(s.substr(2));
        }

        map[s] = res;

        return res;
    }

    unordered_map<string, int> map;
};

