/*
 *  Results:    AC (16 ms [90.66%];  18 MB [64.59%])
 */


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int remain = 0.5 * nums.size() * (nums.size()+1);

        for (const int n : nums)
            remain -= n;

        return remain;
    }
};

