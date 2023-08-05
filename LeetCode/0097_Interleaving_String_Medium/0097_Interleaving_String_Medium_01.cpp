/*
 *  Results:    AC (0 ms [100.00%];  7.1 MB [57.86%])
 */


// #define TLE
#ifndef TLE
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size(), vector<int>(s2.size(), -1));
        return dfs(0, 0, 0, s1, s2, s3);
    }
private:
    bool dfs(const int idx1, const int idx2, const int idx3, const string &s1, const string &s2, const string &s3) {
        if (idx3 >= s3.size()) {
            // printf("s1[%d], s2[%d], s3[%d], END!\n", idx1, idx2, idx3);
            return (idx1 == s1.size() && idx2 == s2.size()) ? true : false;
        }
        if (idx1 < s1.size() && idx2 < s2.size() && dp.at(idx1).at(idx2) != -1) {
            // printf("s1[%d], s2[%d], s3[%d] => in dp\n", idx1, idx2, idx3);
            return dp.at(idx1).at(idx2);
        }

        // printf("s1[%d], s2[%d], s3[%d]\n", idx1, idx2, idx3);
        if ((idx1 < s1.size() && s1.at(idx1) == s3.at(idx3))
                && (idx2 < s2.size() && s2.at(idx2) == s3.at(idx3))) {
            return dp.at(idx1).at(idx2) =
                (dfs(idx1+1, idx2, idx3+1, s1, s2, s3) ||
                dfs(idx1, idx2+1, idx3+1, s1, s2, s3));
        } else {
            if (idx1 < s1.size() && s1.at(idx1) == s3.at(idx3))
                return dfs(idx1+1, idx2, idx3+1, s1, s2, s3);
            if (idx2 < s2.size() && s2.at(idx2) == s3.at(idx3))
                return dfs(idx1, idx2+1, idx3+1, s1, s2, s3);
        }
        return false;
    }
    vector<vector<int>> dp;
};
#else
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return dfs(0, 0, 0, s1, s2, s3);
    }
private:
    bool dfs(const int idx1, const int idx2, const int idx3, const string &s1, const string &s2, const string &s3) {
        // printf("s1[%d], s2[%d], s3[%d]\n", idx1, idx2, idx3);
        if (idx3 >= s3.size())
            return (idx1 == s1.size() && idx2 == s2.size()) ? true : false;

        if ((idx1 < s1.size() && s1.at(idx1) == s3.at(idx3))
                && (idx2 < s2.size() && s2.at(idx2) == s3.at(idx3))) {
            return (dfs(idx1+1, idx2, idx3+1, s1, s2, s3) ||
                dfs(idx1, idx2+1, idx3+1, s1, s2, s3));
        } else {
            if (idx1 < s1.size() && s1.at(idx1) == s3.at(idx3))
                return dfs(idx1+1, idx2, idx3+1, s1, s2, s3);
            if (idx2 < s2.size() && s2.at(idx2) == s3.at(idx3))
                return dfs(idx1, idx2+1, idx3+1, s1, s2, s3);
        }
        return false;
    }
};
#endif

