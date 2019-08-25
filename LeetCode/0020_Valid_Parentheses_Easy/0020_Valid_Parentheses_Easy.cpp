/**
 *  LeetCode: 20. Valid Parentheses (Easy)
 *
 *      Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 *      An input string is valid if:
 *
 *          Open brackets must be closed by the same type of brackets.
 *          Open brackets must be closed in the correct order.
 *
 *      Note that an empty string is also considered valid.
 *
 *
 *      Example:    1. "()" => true;    2. "()[]{}" => true;    3. "(]" => false;   4. "([)]" => false;     5. "{[]}" => true;
 *
 *
 *  Results:    AC (0 ms; 8.4 MB)
 */


#include <stack>

class Solution {
public:
    bool isValid(string s) {                
        stack<char> brackets;
        for (int i = 0; i < s.length(); ++i) {
            // left parentheses => push to stack.
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                brackets.push(s[i]);
            }
            
            // right parentheses => check stack. correct => pop; incorrect => return false;
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if ( (brackets.empty()) || (s[i] == ')' && brackets.top() != '(') || (s[i] == '}' && brackets.top() != '{') || (s[i] == ']' && brackets.top() != '[')) {
                    return false;
                }
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};