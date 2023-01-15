/*
 *  Results:    AC (34 ms [94.60%];  27.6 MB [66.59%])
 */


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            const int idx = (l + r) / 2;

            if (target == nums[idx])
                return idx;
            if (target < nums[idx])
                r = idx - 1;
            else
                l = idx + 1;
        }

        return -1;
    }
};

