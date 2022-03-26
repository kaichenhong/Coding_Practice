/**
 *  LeetCode: 371. Sum of Two Integers (Easy)
 *
 *      Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 *
 *      Example:    1. a = 1, b = 2 => 3.
 *                  2. a = -2, b = 3 => 1.
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  8 MB [100.00%])
 */


class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0)   return b;
        if (b == 0)   return a;

        int sum = a ^ b, carry = a & b;
        while (carry != 0) {
            carry &= 0x7FFFFFFF;
            carry <<= 1;
            int lastSum = sum;
            sum ^= carry;
            carry &= lastSum;
        }
        //return getSum(a ^ b, (a & b & 0x7FFFFFFF) << 1);
        return sum;
    }
};

//  6+3=9 =>   0x0110
//          +  0x0011
//          ---------
//          =  0x1001
//  =================
//  6 XOR 9 => 0x0101   sum
//  6 AND 9 => 0x0010   carry
//  shift 1 => 0x0100   carry_shift1
//    XOR   => 0x0001   sum = (sum ^ carry_shift1)
//    AND   => 0x0100   carry
//  shift 1 => 0x1000   carry_shift1
//    XOR   => 0x1001   sum = (sum ^ carry_shift1)
//    AND   => 0x0000   carry