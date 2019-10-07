/**
 *  LeetCode: 62. Unique Paths (Medium)
 *
 *     A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 *     The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 *     How many possible unique paths are there?
 *
 *     Note:   m and n will be at most 100.
 *
 *
 *
 *      Example:    1. m = 3, n = 2 => 3; (From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 *                                          1. Right -> Right -> Down
 *                                          2. Right -> Down -> Right
 *                                          3. Down -> Right -> Right)    
 *                  2. m = 7, n = 3 => 28;
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.1 MB [100.00%])
 */


class Solution {
public:
    int uniquePaths(int m, int n) {
        int minVal = min(m, n);
        if (minVal == 1)    return 1;

        return combination(m+n-2, minVal-1);
    }

private:
    int combination(int m, int n) {
        size_t val = 1;
        for (int i = 0; i < n; ++i) {
            val *= (m-i);
            val /= i+1;
        }
        return int(val);
    }
};