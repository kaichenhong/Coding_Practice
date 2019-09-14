/**
 *  LeetCode: 219. Contains Duplicate II (Easy)
 *
 *      Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 *
 *
 *      Example:    1. nums = [1,2,3,1], k = 3 => true.
 *                  2. nums = [1,0,1,1], k = 1 => true.
 *                  3. nums = [1,2,3,1,2,3], k = 2 => false.
 *
 *
 *
 *  Results:    AC (12 ms [99.70%];  15.3 MB [82.35%])
 */


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // speed up cin/cout.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if (nums.size() == 0 || nums.size() == 1)
            return false;

        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); ++i) {
            if (table.find(nums[i]) == table.end()) {
                table[nums[i]] = i;
            }
            else {
                if ((i - table[nums[i]]) <= k) {
                    return true;
                }
                else {
                    table[nums[i]] = i;
                }
            }

        }
        return false;
    }
};