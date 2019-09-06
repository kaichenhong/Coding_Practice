/**
 *  LeetCode: 190. Reverse Bits (Easy)
 *
 *      Reverse bits of a given 32 bits unsigned integer.
 *
 *
 *      Example:    1. 00000010100101000001111010011100 => 00111001011110000010100101000000;
 *                  2. 11111111111111111111111111111101 => 10111111111111111111111111111111;
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.1 MB [95.83%])
 */


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverseInt = 0;
        for (int i = 0; i < 32; ++i) {
            reverseInt |= n & 1;
            if (i == 31)    break; 
            n >>= 1;
            reverseInt <<= 1;
        }
        return reverseInt;
    }
};