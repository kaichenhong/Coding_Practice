/*
 *  Results:    AC (8 ms [94.07%];  10.4 MB [86.60%])
 */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            auto it = std::lower_bound(dp.begin(), dp.end(), nums[i]);

            if (it == dp.end())
                dp.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return dp.size();
    }
};

