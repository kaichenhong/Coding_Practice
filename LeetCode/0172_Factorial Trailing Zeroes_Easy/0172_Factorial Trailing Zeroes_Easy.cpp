/**
 *  LeetCode: 172. Factorial Trailing Zeroes (Easy)
 *
 *      Given an integer n, return the number of trailing zeroes in n!.
 *
 *
 *      Example:    1. 3 => 0;  3! = 6, no trailing zero.    
 *                  2. 5 => 1;  5! = 120, one trailing zero.
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.1 MB [100.00%])
 */


class Solution {
public:
    int trailingZeroes(int n) {

        /**
         *  How to generate a "0"?
         *      2 * 5 = 10, and '2' is more than '5'.
         *      count multipy how many '5'.
         */
        int counter = 0, divisor = 1;
        while(true) {
            divisor *= 5;
            int count = n / divisor;
            if (count == 0)   break;
            counter += count;
            if (divisor > INT_MAX / 5)  break; 
        }
        return counter;
    }
};