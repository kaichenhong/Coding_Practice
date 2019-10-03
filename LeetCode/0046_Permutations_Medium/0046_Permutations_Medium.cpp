/**
 *  LeetCode: 46. Permutations (Medium)
 *
 *     Given a collection of distinct integers, return all possible permutations.
 *
 *
 *
 *      Example:    1. [1,2,3] => [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ];
 *
 *
 *  Results:    AC (8 ms [98.53%];  9.2 MB [98.51%])
 */


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() == 0)   return results;

        solver(nums, 0, results);
        return results;
    }

private:
    void solver(vector<int> &nums, size_t headIdx, vector<vector<int>> &results) {
        if (headIdx >= nums.size()) {
            results.push_back(nums);
        }
        else {
            for (size_t i = headIdx; i < nums.size(); ++i) {
                if (headIdx != i) {
                    //swap(nums[headIdx], nums[i]);

                    // For lexicographical
                    size_t rear = i;
                    while (rear > headIdx) {
                        swap(nums[rear-1], nums[rear]);
                        rear--;
                    }
                }
                solver(nums, headIdx+1, results);
                if (headIdx != i) {
                    //swap(nums[headIdx], nums[i]);

                    // For lexicographical
                    size_t head = headIdx;
                    while (head < i) {
                        swap(nums[head], nums[head+1]);
                        head++;
                    }
                }
            }
        }
    }
};


/**
 *  [1,2,3,4], => [ [1,2,3,4], [1,2,4,3], [1,3,2,4], [1,3,4,2], [1,4,2,3], [1,4,3,2],
 *                  [2,1,3,4], [2,1,4,3], [2,3,1,4], [2,3,4,1], [2,4,1,3], [2,4,3,1],
 *                  [3,1,2,4], [3,1,4,2], [3,2,1,4], [3,2,4,1], [3,4,1,2], [3,4,2,1],
 *                  [4,1,2,3], [4,1,3,2], [4,2,1,3], [4,2,3,1], [4,3,1,2], [4,3,2,1] ]
 */