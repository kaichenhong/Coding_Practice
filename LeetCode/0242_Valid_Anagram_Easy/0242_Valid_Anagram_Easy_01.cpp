/*
 *  Results:    AC (6 ms [89.07%];  7.2 MB [78.25%])
 */


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letters_set(26, 0);

        for (const char c : s)
            letters_set[c-'a']++;
        for (const char c : t)
            letters_set[c-'a']--;

        for (int i = 0; i < 26; ++i)
            if (letters_set[i] != 0)
                return false;

        return true;
    }
};

