/*
 *  Results:    AC (0 ms [100.00%];  7.8 MB [88.75%])
 */


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);

        for (int i = 0; i < n+1; ++i)
            res[i] = __builtin_popcount(i);

        return res;
    }
};

