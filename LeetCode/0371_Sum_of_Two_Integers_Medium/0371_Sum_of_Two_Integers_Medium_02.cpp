/*
 *  Results:    AC (0 ms [100.00%];  5.8 MB [75.99%])
 */


class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;

        while (b != 0) {
            sum = a ^ b;
            b = (unsigned int)(a & b & 0x7fffffff) << 1;
            a = sum;
        }

        return a;
    }
};

