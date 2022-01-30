/*
 *  Results:    AC (0 ms [100.00%];  7.7 MB [96.94%])
 */


class Solution {
public:
    int rob(vector<int>& nums) {
        int res1 = 0, res2 = 0;

        res1 = dp_solver(nums, 0, nums.size()-1);
        if (nums.size() > 1)
            res2 = dp_solver(nums, 1, nums.size());

        return std::max(res1, res2);
    }
private:
    int dp_solver(const vector<int> &nums, const size_t idx, const size_t len) {
        int dp0 = 0, dp1 = 0, dp2 = nums[idx];

        for (size_t i = idx; i < len; ++i) {
            dp2 = std::max(dp0+nums[i], dp1);

            dp0 = dp1;
            dp1 = dp2;
        }

        return dp2;
    }
};

