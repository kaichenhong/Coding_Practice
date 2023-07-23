/*
 *  Results:    AC (1873 ms [5.10%];  8.9 MB [99.40%])
 */


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(0, 0, nums, target);
        return total_cnt;
    }
private:
    void dfs(const unsigned int index, const int curr_sum, const vector<int> &nums, const int target) {
        if (index >= nums.size()) {
            if (curr_sum == target)
                total_cnt++;
            return;
        }
        dfs(index + 1, curr_sum + nums.at(index), nums, target);
        dfs(index + 1, curr_sum - nums.at(index), nums, target);
    }

    unsigned int total_cnt;
};

