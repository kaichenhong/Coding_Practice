/**
 *  LeetCode: 167. Two Sum II - Input array is sorted (Easy)
 *
 *      Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 *      You may assume that the array is non-empty and the majority element always exist in the array.
 *
 *
 *      Example:    1. [3,2,3] => 3;    2. [2,2,1,1,1,2,2] => 2
 *
 *
 *
 *  Results:    AC (16 ms [96.72%];  11.1 MB [78.79%])
 */


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // use hash table, BUT ***there still has a better way for solving this problem***.
        unordered_map<int, int> counterTable;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = counterTable.find(nums[i]);
            if (iter != counterTable.end()) {
                (iter->second)++;
            }
            else {
                counterTable.insert(pair<int, int>(nums[i], 1));
            }
        }

        for (auto iter = counterTable.begin(); iter != counterTable.end(); ++iter) {
            cout << iter->second << " ";
            if ( iter->second > (nums.size() / 2) )
                return iter->first;
        }
        return 0;
    }
};