/**
 *  LeetCode: 48. Rotate Image (Medium)
 *
 *     You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
 *
 *     Note:   You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 *
 *
 *
 *      Example:    1. [1,2,3]          [7,4,1]
 *                     [4,5,6]    =>    [8,5,2]
 *                     [7,8,9]          [9,6,3]
 *
 *
 *  Results:    AC (4 ms [81.57%];  9 MB [85.37%])
 */


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        swapCol(matrix);
    }

private:
    void transpose(vector<vector<int>>& matrix) {
        size_t rows = matrix.size(), cols = matrix[0].size();
        for (size_t row = 0; row < rows; ++row) {
            for (size_t col = row; col < cols; ++col) {
                if (row == col)  continue;
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }

    void swapCol(vector<vector<int>>& matrix) {
        size_t rows = matrix.size(), cols = matrix[0].size();
        for (size_t row = 0; row < rows; ++row) {
            for (size_t col = 0; col < cols/2; ++col) {
                swap(matrix[row][col], matrix[row][cols-1-col]);
            }
        }
    }
};