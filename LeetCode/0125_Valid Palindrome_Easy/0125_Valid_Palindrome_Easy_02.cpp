/**
 *  LeetCode: 125. Valid Palindrome (Easy)
 *
 *      Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 *      Note: For the purpose of this problem, we define empty string as valid palindrome.
 *
 *
 *      Example:    1. "A man, a plan, a canal: Panama" => true.
 *
 *                  2. "race a car" => false.
 *
 *
 *
 *  Results:    AC (4 ms [92.44%];  7.4 MB [71.28%])
 */


class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1)
            return true;

        int head = 0, tail = s.size()-1;
        while (head <= tail) {
            while (head < s.size() && !isalnum(s[head]))
                head++;
            while (tail >= 0 && !isalnum(s[tail]))
                tail--;

            if (head > tail)
                return true;

            if (std::tolower(s[head]) != std::tolower(s[tail]))
                return false;

            head++;
            tail--;
        }

        return true;
    }
};

