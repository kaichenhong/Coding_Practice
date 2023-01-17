/*
 *  Results:    AC (0 ms [100.00%];  9.4 MB [96.42%])
 */


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const size_t m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            const size_t med = (left + right) / 2;
            const size_t row = med / n, col = med % n;

            if (target == matrix[row][col])
                return true;

            if (target < matrix[row][col])
                right = med - 1;
            else
                left = med + 1;
        }

        return false;
    }
};

