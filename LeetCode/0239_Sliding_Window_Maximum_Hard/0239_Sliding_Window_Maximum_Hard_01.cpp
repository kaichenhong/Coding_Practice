/*
 *  Results:    AC (294 ms [92.53%];  134.6 MB [83.15%])
 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<unsigned int> deq;

        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (!deq.empty() && deq.front() + k <= i)
                deq.pop_front();
            while (!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();
            deq.push_back(i);

            if (i + 1 >= k)
                result.push_back(nums[deq.front()]);
        }

        return result;
    }
};

