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
 *  Results:    AC (44 ms [92.59%];  11.4 MB [100.00%])
 */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // speed up cin/cout.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        bool findFirstZero = false, clearThisRow = false;
        size_t refRow = 0;
        for (size_t row = 0; row < matrix.size(); ++row) {
            for (size_t col = 0; col < matrix[0].size(); ++col) {
                if (!findFirstZero && matrix[row][col] == 0) {
                    findFirstZero = true;
                    refRow = row;
                    break;
                }

                if (row != refRow && matrix[row][col] == 0) {
                    clearThisRow = true;
                    matrix[refRow][col] = 0;
                }
            }
            if (row != refRow && clearThisRow) {
                clearThisRow = false;
                for (size_t col = 0; col < matrix[0].size(); ++col) {
                    matrix[row][col] = 0;
                }
            }
        }

        for (size_t col = 0; col < matrix[0].size(); ++col) {
            if (matrix[refRow][col] == 0) {
                for (size_t row = 0; row < matrix.size(); ++row) {
                    matrix[row][col] = 0;
                }
            }
        }
        if (findFirstZero) {
            for (size_t col = 0; col < matrix[0].size(); ++col) {
                matrix[refRow][col] = 0;
            }
        }
    }
};