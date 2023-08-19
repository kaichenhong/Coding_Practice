/*
 *  Results:    AC (0 ms [100.00%];  6.0 MB [97.17%])
 */


class Solution {
public:
    bool checkValidString(string s) {
        const int len = s.size();
        int l_cnt = 0, r_cnt = 0, s_cnt = 0;
        bool situ_1 = false, situ_2 = false;

        /* assume '*' is '(', check result */
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(')
                l_cnt++;
            else if (s[i] == ')')
                r_cnt++;
            else
                s_cnt++;

            if (r_cnt > l_cnt + s_cnt)
                return false;
        }
        situ_1 = (l_cnt + s_cnt >= r_cnt);

        /* assume '*' is ')', check result */
        l_cnt = r_cnt = s_cnt = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] == '(')
                l_cnt++;
            else if (s[i] == ')')
                r_cnt++;
            else
                s_cnt++;

            if (l_cnt > r_cnt + s_cnt)
                return false;
        }
        situ_2 = (r_cnt + s_cnt >= l_cnt);

        return (situ_1 && situ_2);
    }
};

