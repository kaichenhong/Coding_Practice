/*
 *  Results:    AC (0 ms [100.00%];  11.7 MB [73.42%])
 */


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return result;
    }
private:
    void dfs(const int l, const int r) {
        // cout << "l:" << l << ", r:" << r << ", string s:" << s << endl;
        if (l == 0 && r == 0) {
            result.push_back(s);
            return;
        }

        /* check remain cnt of left parentheses */
        if (l > 0) {
            s.push_back('(');
            dfs(l-1, r);
            s.pop_back();
        }
        /* left & right parentheses must be pair */
        /* => check left cnt <= right cnt */
        if (l < r) {
            s.push_back(')');
            dfs(l, r-1);
            s.pop_back();
        }
    }

    vector<string> result;
    string s;
};

