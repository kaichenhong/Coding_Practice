/*
 *  Results:    AC (3 ms [92.48%];  6.2 MB [97.13%])
 */


class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); ++i) {
            solver(s, i, i, res);
            solver(s, i, i+1, res);
        }

        return res;
    }
private:
    void solver(const string &s, int l, int r, int &res) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            res++;
        }
    }
};

