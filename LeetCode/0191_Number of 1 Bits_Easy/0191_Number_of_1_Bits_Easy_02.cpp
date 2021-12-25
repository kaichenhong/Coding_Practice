/**
 *  LeetCode: 191. Number of 1 Bits (Easy)
 *
 *      Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
 *
 *
 *      Example:    1. 00000000000000000000000000001011 => 3;
 *                  2. 00000000000000000000000010000000 => 1;
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.0 MB [100.00%])
 */


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;

        for (int i = 0; i < 32; ++i)
            if ((n >> i) & 1U)
                ret++;

        return ret;
    }
};

