/*
 *  Results:    AC (3 ms [94.21%];  7.3 MB [67.34%])
 */


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        queens.reserve(n);
        dfs(0, n, res);
        return res;
    }
private:
    string gen_str(const size_t target, const int n) {
        string st(n, '.');

        st.at(target) = 'Q';
        return st;
    }
    bool check_valid(const size_t row, const size_t col, const int n) {
        /* check the col at the row is valid or not */
        for (const auto &queen : queens) {
            if (queen.second == col)
                return false;

            const int invalid_col_left = queen.second - (row - queen.first);
            const int invalid_col_right = queen.second + (row - queen.first);

            if (invalid_col_left >= 0 && invalid_col_left == col)
                return false;
            if (invalid_col_right < n && invalid_col_right == col)
                return false;
        }
        return true;
    }
    void dfs(const size_t row, const int n, vector<vector<string>> &res) {
        if (row >= n) {
            res.push_back(temp);
            return;
        }

        for (size_t i = 0; i < n; ++i) {
            if (!check_valid(row, i, n))
                continue;

            queens.push_back({row, i});
            temp.push_back(gen_str(i,n));
            dfs(row+1, n, res);
            temp.pop_back();
            queens.pop_back();
        }
    }
    vector<pair<size_t, size_t>> queens;
    vector<string> temp;
};

