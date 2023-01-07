/*
 *  Results:    AC (6 ms [88.54%];  7.2 MB [90.23%])
 */


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        unsigned int l_idx = 0, r_idx = 0;

        for (auto it : s1)
            mp[it]++;

        for (; r_idx < s2.size(); ++r_idx) {
            if (--mp[s2[r_idx]] < 0)
                while (++mp[s2[l_idx++]] != 0);
            else if (r_idx - l_idx + 1 == s1.size())
                return true;
        }

        return false;
    }
};

