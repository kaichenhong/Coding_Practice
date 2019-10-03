/**
 *  LeetCode: 31. Next Permutation (Medium)
 *
 *     Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 *     If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 *     The replacement must be in-place and use only constant extra memory.
 *
 *
 *
 *      Example:    1. [1,2,3] => [1,3,2];
 *                  2. [3,2,1] => [1,2,3];
 *                  3. [1,1,5] => [1,5,1];
 *
 *
 *  Results:    AC (4 ms [98.76%];  8.5 MB [100.00%])
 */


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0)   return;

        bool biggest = true;
        for (size_t i = nums.size()-1; i > 0; --i) {
            if (nums[i] <= nums[i-1])
                continue;

            biggest = false;
            size_t pickHeadIdx = i-1, pickRearIdx = i-1, Idx = i;
            while (Idx < nums.size()) {
                if (nums[Idx] > nums[pickHeadIdx]) {
                    if (Idx > pickRearIdx)
                        pickRearIdx = Idx;
                }
                Idx++;
            }
            swap(nums[pickHeadIdx], nums[pickRearIdx]);
            std::reverse(nums.begin()+pickHeadIdx+1, nums.end());

            break;
        }
        if (biggest)
            std::reverse(nums.begin(), nums.end());
    }
};


/**
 *  [1,2,3,4,5] -> [3,4,5,2,1] => [3,5,1,2,4]
 *              -> [3,5,4,2,1] => [4,1,2,3,5]
 *                                [5,4,2,1,3]
 *
 *  Check problem: permutations, permutations II for more detail.
 */