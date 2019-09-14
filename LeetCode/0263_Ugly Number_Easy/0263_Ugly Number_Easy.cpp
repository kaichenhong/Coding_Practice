/**
 *  LeetCode: 263. Ugly Number (Easy)
 *
 *      Write a program to check whether a given number is an ugly number. Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 *
 *
 *      Example:    1. 6 => true;   6 = 2 × 3.
 *                  2. 8 => true;   8 = 2 × 2 × 2.
 *                  3. 14 => false; 14 is not ugly since it includes another prime factor 7.
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  7.9 MB [100.00%])
 */


class Solution {
public:
    bool isUgly(int num) {
        while (num != 0 && num % 2 == 0) {
            num /= 2;
        }
        while (num != 0 && num % 3 == 0) {
            num /= 3;
        }
        while (num != 0 && num % 5 == 0) {
            num /= 5;
        }

        if (num == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};