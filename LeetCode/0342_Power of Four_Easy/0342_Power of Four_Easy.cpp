/**
 *  LeetCode: 342. Power of Four (Easy)
 *
 *      Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 *
 *
 *      Example:    1. 16 => true.
 *                  2.  5 => false.
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.1 MB [80.95%])
 */


class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1)
            return true;

        int value = 1;
        for (int i = 1; i < 16; ++i) {  // 32 bit Int => 2^32 = 4^16
            value *= 4;
            if (value == num) {
                return true;
            }
            if (value > num) {
                return false;
            }
        }
        return false;
    }
};