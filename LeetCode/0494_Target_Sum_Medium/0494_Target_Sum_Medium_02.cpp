/*
 *  Results:    AC (249 ms [38.68%];  60.7 MB [12.42%])
 */


#if 1
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memo.resize(nums.size());
        return dfs(0, 0, nums, target);
    }
private:
    unsigned int dfs(const unsigned int index, const int curr_sum, const vector<int> &nums, const int target) {
        if (index >= nums.size())
            return (curr_sum == target) ? 1 : 0;
        if (memo[index].count(curr_sum) != 0)
            return memo[index][curr_sum];
        int cnt1 = dfs(index + 1, curr_sum + nums.at(index), nums, target);
        int cnt2 = dfs(index + 1, curr_sum - nums.at(index), nums, target);
        // printf("memo[%u][%d] = %d\n", index, curr_sum, cnt1 + cnt2);
        return memo[index][curr_sum] = cnt1 + cnt2;
    }

    vector<unordered_map<int, unsigned int>> memo;
};
#else
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memo.resize(nums.size());
        return dfs(0, target, nums);
    }
private:
    unsigned int dfs(const unsigned int index, const int target, const vector<int> &nums) {
        if (index >= nums.size())
            return (target == 0) ? 1 : 0;
        if (memo[index].count(target) != 0)
            return memo[index][target];
        int cnt1 = dfs(index + 1, target + nums.at(index), nums);
        int cnt2 = dfs(index + 1, target - nums.at(index), nums);
        // printf("memo[%u][%d] = %d\n", index, target, cnt1 + cnt2);
        return memo[index][target] = cnt1 + cnt2;
    }

    vector<unordered_map<int, unsigned int>> memo;
};
#endif

