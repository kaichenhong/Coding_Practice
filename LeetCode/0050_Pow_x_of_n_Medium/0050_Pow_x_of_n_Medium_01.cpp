/*
 *  Results:    AC (0 ms [100.00%];  5.9 MB [93.86%])
 */


class Solution {
public:
    double myPow(double x, int n) {
        long int abs_n = labs(n);
        double pow = 1;

        while (abs_n) {
            if (abs_n & 1)
                pow *= x;
            x *= x;
            abs_n >>= 1;
        }

        return (n > 0) ? pow : (1 / pow);
    }
};

