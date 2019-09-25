/**
 *  LeetCode: 29. Divide Two Integers (Medium)
 *
 *     Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 *
 *     Return the quotient after dividing dividend by divisor. The integer division should truncate toward zero.
 * 
 *     Note: 1. Both dividend and divisor will be 32-bit signed integers.
 *           2. The divisor will never be 0.
 *           3. Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
 *              For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
 *
 *
 *
 *      Example:    1. dividend = 10, divisor = 3 => 3;
 *                  2. dividend = 7, divisor = -3 => -2;
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.0 MB [100.00%])
 */


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)  return 0;
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))  return INT_MAX;
        if (divisor == 1)   return dividend;
        if (divisor == -1)  return -dividend;
        
        return solver(dividend, divisor);
    }

private:
    int solver(int dividend, int divisor) {
        bool positive = (dividend > 0 && divisor > 0) ||
                        (dividend < 0 && divisor < 0) ? true : false;

        size_t dividendLL = abs(ssize_t(dividend));
        size_t divisorLL = abs(ssize_t(divisor));
        size_t buff = 0;

        int multipiler = 0;
        for (uint32_t i = 0; i < 32; ++i) {
            if (buff + divisorLL > dividendLL) {
                break;
            }

            if (buff + (divisorLL << i) <= dividendLL) {
                continue;
            }
            else {
                buff += (divisorLL << (i-1));
                multipiler |= (1 << (i-1));     // the result is same as using += operator.
                i = -1;                         // in for loop, next time i will be add 1. => -1 + 1 = 0;
            }
        }
        return positive ? multipiler : -multipiler;
    }
};

/*
// Have some errors...
class Solution {
public:
    int divide(int dividend, int divisor) {        
        if(!divisor || (dividend == INT_MIN && divisor == -1))  return INT_MAX;
        if (dividend == 0)  return 0;
        if (divisor == 1)   return dividend;
        if (divisor == -1)  return -dividend;
        
        int multipier = 0;
        bool positive = ((dividend > 0 && divisor > 0) || 
                         (dividend < 0 && divisor < 0)) ? true : false;
        if (dividend > 0) {
            if (positive) {
                while (dividend >= 0) {
                    dividend -= divisor;
                    multipier++;
                }
            }
            else {
                while (dividend >= 0) {
                    dividend += divisor;
                    multipier++;
                }
            }
        }
        else if (dividend < 0) {
            if (positive) {
                while (dividend <= 0) {
                    dividend -= divisor;
                    multipier++;
                }
            }
            else {
                while (dividend <= 0) {
                    dividend += divisor;
                    multipier++;
                }
            }
        }
        return positive ? multipier-1 : -(multipier-1);
    }
};*/