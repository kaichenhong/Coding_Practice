/*
 *  Results:    AC (616 ms [17.95%];  28.9 MB [82.94%])
 */


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        unordered_set<int> table(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); ++i) {
            if (!table.count(nums[i]-1)) {
                int len = 0;

                while (table.count(nums[i]++))
                    len++;

                max = std::max(max, len);
            }
        }

        return max;
    }
};

