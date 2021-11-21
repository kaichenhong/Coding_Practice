/**
 *  Results:    AC (3 ms [99.21%];  7.7 MB [83.02%])
 */


class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> letter_cnt(128, 0);
        int match_cnt = 0, head = 0, min_head = -1, min_len = INT_MAX;

        // create map by using string 't'
        for (size_t i = 0; i < t.size(); ++i)
            letter_cnt[t[i]]++;

        // searching
        for (size_t i = 0; i < s.size(); ++i) {
            // find match char => decrease letter_cnt
            // (for multiple find char before find the window substring),
            // but only when '> 0' will increase match_cnt
            if (letter_cnt[s[i]]-- > 0)
                match_cnt++;

            // find window substring
            while (match_cnt == t.size()) {
                if (min_len >= (i - head + 1)) {
                    min_len = (i - head + 1);
                    min_head = head;
                }

                // pop out head char => increase letter_cnt
                // (for multiple find char before find the window substring),
                // but only when '== 0' will decrease match_cnt
                if (letter_cnt[s[head]]++ == 0)
                    match_cnt--;
                head++;
            }
        }

        return min_head == -1 ? "" : s.substr(min_head, min_len);
    }
};
