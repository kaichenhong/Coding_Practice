/**
 *  LeetCode: 47. Permutations II (Medium)
 *
 *     Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 *
 *
 *      Example:    1. [1,1,2] => [ [1,1,2], [1,2,1], [2,1,1] ];
 *
 *
 *  Results:    AC (20 ms [94.95%];  10.8 MB [30.95%])
 */


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() == 0)  return results;

        sort(nums.begin(), nums.end());
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
                if (i > headIdx && nums[i] == nums[i-1]) {
                    continue;
                }

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