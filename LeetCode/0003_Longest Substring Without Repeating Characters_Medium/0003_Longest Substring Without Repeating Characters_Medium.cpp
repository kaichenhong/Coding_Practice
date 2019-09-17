/**
 *  LeetCode: 3. Longest Substring Without Repeating Characters (Medium)
 *
 *      Given a string, find the length of the longest substring without repeating characters.
 *
 *
 *
 *      Example:    1. "abcabcbb" => 3;     The answer is "abc", with the length of 3. 
 *                  2. "bbbbb" => 1;        The answer is "b", with the length of 1.
 *                  3. "pwwkew" => 3;       The answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 *
 *  Results:    AC (4 ms [99.37%];  10.4 MB [72.64%])
 */


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // speed up cin/cout.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if (s.length() == 0 || s.length() == 1)   return s.length();

        vector<int> checker(256, -1);   // ASCII with extend => 255 (8 bits, 256 characters);
        int head = 0, rear = 0, longestLength = 0;
        for (rear = 0; rear < s.length(); ++rear) {
            if (checker[s[rear]] != -1 &&
                checker[s[rear]] >= head) 
            {
                longestLength = max((rear - head), longestLength);
                head = checker[s[rear]] + 1;
            }
            checker[s[rear]] = rear;
        }
        return max((rear - head), longestLength);
    }
};


/**
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1)   return s.length();

        unordered_map<char, int> checker;
        int head = 0, rear = 0, longestLength = 0;
        for (rear = 0; rear < s.length(); ++rear) {
            if (checker.find(s[rear]) != checker.end() &&
                checker[s[rear]] >= head) 
            {
                longestLength = max((rear - head), longestLength);
                head = checker[s[rear]] + 1;
            }
            checker[s[rear]] = rear;
        }
        return max((rear - head), longestLength);
    }
};
 */