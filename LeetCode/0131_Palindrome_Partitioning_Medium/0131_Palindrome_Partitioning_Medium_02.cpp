/*
 *  Results:    AC (122 ms [70.24%];  75.7 MB [35.54%])
 */


class Solution {
public:
    vector<vector<string>> partition(string s) {
        const size_t n = s.size();

        dfs(0, n, s);
        return results;
    }
private:
    bool is_palindrome(size_t i, size_t j, const string &s) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void dfs(const size_t start_idx, const size_t n, const string &s) {
        if (start_idx >= n) {
            results.push_back(sub_res);
            return;
        }

        for (size_t i = start_idx; i < n; ++i) {
            if (!is_palindrome(start_idx, i, s))
                continue;

            const string sub = s.substr(start_idx, i - start_idx + 1);
            sub_res.push_back(s.substr(start_idx, i - start_idx + 1));
            dfs(i+1, n, s);
            sub_res.pop_back();
        }
    }

    vector<string> sub_res;
    vector<vector<string>> results;
};

