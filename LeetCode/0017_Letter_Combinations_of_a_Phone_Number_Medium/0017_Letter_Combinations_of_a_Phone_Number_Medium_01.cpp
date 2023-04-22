/*
 *  Results:    AC (0 ms [100.00%];  6.4 MB [80.82%])
 */


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.empty())
            return res;

        /* init dict */
        dict.resize(10);
        dict[0] = {' '};
        dict[1] = {};
        dict[2] = {'a', 'b', 'c'};
        dict[3] = {'d', 'e', 'f'};
        dict[4] = {'g', 'h', 'i'};
        dict[5] = {'j', 'k', 'l'};
        dict[6] = {'m', 'n', 'o'};
        dict[7] = {'p', 'q', 'r', 's'};
        dict[8] = {'t', 'u', 'v'};
        dict[9] = {'w', 'x', 'y', 'z'};

        dfs(digits, 0, res);
        return res;
    }
private:
    void dfs(const string &digits, const int l, vector<string> &res) {
        if (l >= digits.size()) {
            res.push_back(temp);
            return;
        }

        for (const auto &c : dict[(digits[l] - '0')]) {
            temp.push_back(c);
            dfs(digits, l+1, res);
            temp.pop_back();
        }
    }

    vector<vector<char>> dict;
    string temp;
};

