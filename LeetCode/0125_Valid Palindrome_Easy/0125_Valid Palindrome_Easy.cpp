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
 *  Results:    AC (4 ms [99.15%];  9.3 MB [97.96%])
 */


class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.length();
        int leftIdx = 0, rightIdx = length-1;
        while (leftIdx <= rightIdx) {
            while (!isalnum(s[leftIdx]) && leftIdx < length-1)
                leftIdx++;
            while (!isalnum(s[rightIdx]) && rightIdx > 0)
                rightIdx--;
            if (leftIdx > rightIdx) {
                break;
            }
            
            if (s[leftIdx] <= 'Z' && s[leftIdx] >= 'A')
                s[leftIdx] -= ('Z' - 'z');
            if (s[rightIdx] <= 'Z' && s[rightIdx] >= 'A')
                s[rightIdx] -= ('Z' - 'z');
            

            if (s[leftIdx] != s[rightIdx]) {
                return false;
            }
            leftIdx++;
            rightIdx--;
        }
        return true;
    }
};