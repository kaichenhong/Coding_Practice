/*
 *  Results:    AC (24 ms [99.79%];  16.0 MB [46.37%])
 */


// down, right, up, left
const int dir_r[4] = {1, 0, -1, 0};
const int dir_c[4] = {0, 1, 0, -1};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;

        rows = matrix.size();
        cols = matrix[0].size();
        dp.resize(rows+1, vector<int>(cols+1, -1));
        for (unsigned int r = 0; r < rows; ++r)
            for (unsigned int c = 0; c < cols; ++c)
                ret = max(ret, 1 + dfs(matrix, r, c));
        return ret;
    }
private:
    inline bool chk_boundary_valid(const int r, const int c) {
        return (r >= 0 && r < rows && c >= 0 && c < cols) ? true : false;
    }
    int dfs(const vector<vector<int>> &matrix, const int r, const int c) {
        int local_max = 0;

        if (dp[r][c] != -1)
            return dp[r][c];
        for (unsigned int i = 0; i < 4; ++i) {
            const int new_r = (r + dir_r[i]), new_c = (c + dir_c[i]);

            if (chk_boundary_valid(new_r, new_c))
                if (matrix[new_r][new_c] > matrix[r][c])
                    local_max = max(local_max, 1 + dfs(matrix, new_r, new_c));
        }
        dp[r][c] = local_max;
        return local_max;
    }
    vector<vector<int>> dp;
    unsigned int rows;
    unsigned int cols;
};

/*
9  9  4
6  6  8
2  1  1
=> smaller
0  0  0  0
----------
0  4  3  2
0  3  2  1
0  2  1  0

3  4  5
3  2  6
2  2  1
=>
0  0  0  0
----------
0  4  3  2
0  2  1  1
0  1  2  1
*/

