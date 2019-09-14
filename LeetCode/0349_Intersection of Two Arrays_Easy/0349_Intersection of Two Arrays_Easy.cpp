/**
 *  LeetCode: 349. Intersection of Two Arrays (Easy)
 *
 *      Given two arrays, write a function to compute their intersection.
 *
 *
 *      Example:    1. nums1 = [1,2,2,1], nums2 = [2,2] => [2].
 *                  2. nums1 = [4,9,5], nums2 = [9,4,9,8,4] => [9,4].
 *
 *
 *
 *  Results:    AC (4 ms [99.29%];  9.3 MB [63.33%])
 */


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // speed up cin/cout.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if (nums1.size() == 0 || nums2.size() == 0) {
            return vector<int>{};
        }

        unordered_map<int, bool> checkNums;
        for (size_t i = 0; i < nums1.size(); ++i) {
            if (checkNums.find(nums1[i]) == checkNums.end()) {
                checkNums[nums1[i]] = false;
            }
        }
        vector<int> ans;
        for (size_t i = 0; i < nums2.size(); ++i) {
            if (checkNums.find(nums2[i]) != checkNums.end() &&
                checkNums.find(nums2[i])->second == false) 
            {
                ans.push_back(nums2[i]);
                checkNums[nums2[i]] = true;
            }
        }
        return ans;
    }
};