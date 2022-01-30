/*
 *  Results:    AC (80 ms [77.74%];  46.7 MB [63.01%])
 */


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size()-1; ++i)
            if (nums[i] == nums[i+1])
                return true;

        return false;
    }

    /*bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> map;

        for (const int num : nums) {
            if (map.count(num))
                return true;

            map.insert(num);
        }

        return false;
    }*/
};

