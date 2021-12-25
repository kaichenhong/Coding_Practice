/*
 *  Results:    AC (0 ms [100.00%];  10.1 MB [68.94%])
 */


class Solution {
public:
    int findMin(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
private:
    int dfs(const vector<int> &nums, int f_idx, int t_idx) {
        int front = nums[f_idx], tail = nums[t_idx];
        int m_idx = (f_idx+t_idx)/2, mid = nums[m_idx];

        if (f_idx+1 >= t_idx)
            return min(nums[f_idx], nums[t_idx]);

        if (f_idx == t_idx)
            return nums[f_idx];

        if ((front > tail) && (front < mid))
            return dfs(nums, m_idx, t_idx);
        if ((front > tail) && (front > mid))
            return dfs(nums, f_idx+1, m_idx);

        return dfs(nums, f_idx, m_idx);
    }
};

