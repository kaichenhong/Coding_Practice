/**
 *  LeetCode: 49. Group Anagrams (Medium)
 *
 *     Given an array of strings, group anagrams together.
 *
 *     Note:   All inputs will be in lowercase. The order of your output does not matter.
 *
 *
 *      Example:    1. ["eat", "tea", "tan", "ate", "nat", "bat"] => [ ["ate","eat","tea"], ["nat","tan"], ["bat"] ]
 *
 *
 *  Results:    AC (20 ms [99.97%];  17.4 MB [100.00%])
 */


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        if (strs.size() == 0)  return results;

        unordered_map<string, size_t> table;
        for (size_t i = 0; i < strs.size(); ++i) {
            string uniqStr = strs.at(i);
            sort(uniqStr.begin(), uniqStr.end());
            if (table.find(uniqStr) == table.end()) {
                table[uniqStr] = results.size();
                results.push_back(vector<string>{strs.at(i)});
            }
            else {
                results[table[uniqStr]].push_back(strs.at(i));
            }
        }

        return results;
    }
};