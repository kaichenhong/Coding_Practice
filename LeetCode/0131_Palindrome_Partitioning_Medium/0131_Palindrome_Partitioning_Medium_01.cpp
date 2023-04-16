/*
 *  Results:    AC (98 ms [90.09%];  75.8 MB [35.54%])
 */


class Solution {
public:
    vector<vector<string>> partition(string s) {
        const size_t n = s.size();

        /* build up dp table for faster lookup/checking */
        dp_table.resize(n, vector<bool>(n, false));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j <= i; ++j) {
                if ((s[i] == s[j]) && ((i - j <= 2) || (dp_table[j+1][i-1] == true)))
                    dp_table[j][i] = true;
            }
        }

        dfs(0, n, s);
        return results;
    }
private:
    void dfs(const size_t start_idx, const size_t n, const string &s) {
        if (start_idx >= n) {
            results.push_back(sub_res);
            return;
        }

        for (size_t i = start_idx; i < n; ++i) {
            if (!dp_table[start_idx][i])
                continue;

            const string sub = s.substr(start_idx, i - start_idx + 1);
            sub_res.push_back(s.substr(start_idx, i - start_idx + 1));
            dfs(i+1, n, s);
            sub_res.pop_back();
        }
    }

    vector<vector<bool>> dp_table;
    vector<string> sub_res;
    vector<vector<string>> results;
};

