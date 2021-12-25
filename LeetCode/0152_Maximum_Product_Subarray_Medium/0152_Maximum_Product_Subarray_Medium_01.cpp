/*
 *  Results:    AC (0 ms [100.00%];  13.8 MB [10.22%])
 */


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], mx = res, mn = res;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0)
                swap(mx, mn);

            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);
            res = max(res, mx);
        }

        return res;
    }
};

