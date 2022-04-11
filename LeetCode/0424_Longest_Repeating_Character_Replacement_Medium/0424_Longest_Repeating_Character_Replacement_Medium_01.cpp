/*
 *  Results:    AC (3 ms [98.83%];  6.8 MB [97.14%])
 */


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int max_cnt = 0, start = 0, res = 0;

        for (int i = 0; i < s.size(); ++i) {
            max_cnt = std::max(++cnt[s[i] - 'A'], max_cnt);

            while ((((i+1) - start) - max_cnt) > k) {
                --cnt[s[start] - 'A'];
                ++start;
            }

            res = std::max(((i+1)-start), res);
        }

        return res;
    }
};

