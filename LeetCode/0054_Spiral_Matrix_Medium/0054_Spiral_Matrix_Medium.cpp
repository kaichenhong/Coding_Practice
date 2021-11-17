/**
 *  LeetCode: 54. Spiral Matrix (Medium)
 *
 *  Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 *
 *  Example:
 *
 *      Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 *      Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 *      Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 *      Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *      Constraints:
 *          m == matrix.length
 *          n == matrix[i].length
 *          1 <= m, n <= 10
 *          -100 <= matrix[i][j] <= 100
 *
 *  Results:    AC (0 ms [100.00%];  6.8 MB [92.50%])
 */


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int boundary_top = 0, boundary_down = matrix.size()-1;
        int boundary_left = 0, boundary_right = matrix[0].size()-1;

        while (boundary_top <= boundary_down && boundary_left <= boundary_right) {
            // top : left -> right
            for (int i = boundary_left; i <= boundary_right; ++i)
                res.push_back(matrix[boundary_top][i]);
            // rigth : top -> down
            for (int i = boundary_top+1; i <= boundary_down; ++i)
                res.push_back(matrix[i][boundary_right]);

            if (boundary_top < boundary_down && boundary_left < boundary_right) {
                // down : right -> left
                for (int i = boundary_right-1; i >= boundary_left; --i)
                    res.push_back(matrix[boundary_down][i]);
                // left : down -> top
                for (int i = boundary_down-1; i > boundary_top; --i)
                    res.push_back(matrix[i][boundary_left]);
            }

            // update boundary
            boundary_top++;
            boundary_right--;
            boundary_down--;
            boundary_left++;
        }

        return res;
    }
};

