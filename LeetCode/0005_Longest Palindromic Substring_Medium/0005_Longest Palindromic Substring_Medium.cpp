/**
 *  LeetCode: 5. Longest Palindromic Substring (Medium)
 *
 *      Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 *
 *
 *      Example:    1. "babad" => "bab";     "aba" is also a valid answer.
 *                  2. "cbbd" => "bb";
 *
 *
 *  Results:    AC (12 ms [87.88%];  8.7 MB [91.72%])
 */


class Solution {
public:
    string longestPalindrome(string s) {
        // speed up cin/cout.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if (s.length() == 0 || s.length() == 1)
            return s;

        size_t lengthMax = 0, head = 0, rear = 0;
        for (size_t center = 1; center < s.length(); ++center) {
            size_t head_buff = 0, rear_buff = 0;
            checker(center, s, head_buff, rear_buff);
            size_t length = rear_buff - head_buff + 1;
            if (length > lengthMax) {
                lengthMax = length;
                head = head_buff;
                rear = rear_buff;
            }
        }

        string substring;
        for (size_t i = head; i <= rear; ++i) {
            substring += s[i];
        }
        return substring;
    }

private:
    void checker(size_t &centerIdx, string &s, size_t &head, size_t &rear) {
        size_t border = min(centerIdx, (s.length() - centerIdx - 1));

        size_t head_odd = 0, rear_odd = 0;
        for (size_t offset = 1; offset <= border; ++offset) {
            // check odd.
            //if (s[centerIdx - offset] != s[centerIdx + offset]) {
            if (s.at(centerIdx - offset) != s.at(centerIdx + offset)) {
                break;
            }
            head_odd = centerIdx - offset;
            rear_odd = centerIdx + offset;
        }

        size_t head_even = 0, rear_even = 0;
        //if (s.length() % 2 == 0)
            border = min(centerIdx, (s.length() - centerIdx));
        for (size_t offset = 0; offset < border; ++offset) {
            //if (s[centerIdx - 1 - offset] != s[centerIdx + offset]) {
            if (s.at(centerIdx - 1 - offset) != s.at(centerIdx + offset)) {
                break;
            }
            head_even = centerIdx - 1 - offset;
            rear_even = centerIdx + offset;
        }

        if ( (rear_odd - head_odd) > (rear_even - head_even) ) {
            head = head_odd;
            rear = rear_odd;
        }
        else {
            head = head_even;
            rear = rear_even;
        }
    }
};