/*
 *  Results:    AC (95 ms [99.12%];  61.3 MB [67.12%])
 */


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums.at(0), hare = nums.at(0);

        do {
            tortoise = nums.at(tortoise);
            hare = nums.at(nums.at(hare));
        } while (tortoise != hare);

        tortoise = nums.at(0);
        while (tortoise != hare) {
            tortoise = nums.at(tortoise);
            hare = nums.at(hare);
        }

        return hare;
    }
};

