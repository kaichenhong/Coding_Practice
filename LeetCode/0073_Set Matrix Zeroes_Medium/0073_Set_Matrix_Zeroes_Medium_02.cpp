/**
 *  LeetCode: 73. Set Matrix Zeroes (Medium)
 *
 *      Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 *
 *      Note: A straight forward solution using O(mn) space is probably a bad idea. A simple improvement uses O(m + n) space, but still not the best solution.
 *
 *            Could you devise a constant space solution?
 *
 *
 *
 *      Example:    1.  [1,1,1]        [1,0,1]
 *                      [1,0,1]   =>   [0,0,0]
 *                      [1,1,1]        [1,0,1]
 *
 *                  2.  [0,1,2,0]        [0,0,0,0]
 *                      [3,4,5,2]   =>   [0,4,5,0]
 *                      [1,3,1,5]        [0,3,1,0]
 *
 *
 *
 *
 *  Results:    AC (4 ms [99.87%];  13.1 MB [80.95%])
 */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::bitset<200> clear_rows, clear_cols;

        if (matrix.empty())
            return;

        for (size_t row = 0; row < matrix.size(); ++row) {
            for (size_t col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == 0) {
                    clear_rows.set(row);
                    clear_cols.set(col);
                }

            }
        }

        for (size_t i = 0; i < clear_rows.size(); ++i) {
            if (clear_rows[i] == 0)
                continue;

            for (size_t col = 0; col < matrix[0].size(); ++col)
                matrix[i][col] = 0;
        }

        for (size_t i = 0; i < clear_cols.size(); ++i) {
            if (clear_cols[i] == 0)
                continue;

            for (size_t row = 0; row < matrix.size(); ++row)
                matrix[row][i] = 0;
        }
    }
};

