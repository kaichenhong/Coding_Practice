/*
 *  Results:    AC (0 ms [100.00%];  6.6 MB [86.67%])
 */


class Solution {
public:
    vector<int> partitionLabels(string s) {
        const unsigned int len = s.size();
        unsigned int loc_min_idx = 0, loc_max_idx = 0;
        vector<int> res;

        init_mp_data(s, len);
        for (unsigned int i = 0; i < len; ++i) {
            if (i > loc_max_idx) {
                res.push_back(i - loc_min_idx);
                loc_min_idx = i;
            }
            loc_max_idx = max(loc_max_idx, mp[s[i] - 'a']);
        }
        res.push_back(len - loc_min_idx);

        return res;
    }
private:
    inline void init_mp_data(const string &s, const unsigned int len) {
        memset(mp, 0, sizeof(mp));
        for (unsigned int i = 0; i < len; ++i)
            mp[s[i] - 'a'] = i;
    }
    unsigned int mp[26];
};

/*
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
==>
012345678901234567890123
ababcbacadefegdehijhklij
------------------------
a: 0 - 8
b: 1 - 5
c: 4 - 7
d: 9 - 14
e: 10 - 15
f: 11 - 11
g: 13 - 13
h: 16 - 19
i: 17 - 22
j: 18 - 23
k: 20 - 20
l: 21 - 21
*/

