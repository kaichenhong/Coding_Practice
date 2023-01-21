/*
 *  Results:    AC (35 ms [90.99%];  90.4 MB [9.15%])
 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        split_into_min_max_heap(nums1);
        split_into_min_max_heap(nums2);

        return (max_q.size() == min_q.size())
            ? ((double)(max_q.top() + min_q.top()) / 2)
            : ((double)(max_q.top()));
    }

private:
    void split_into_min_max_heap(const vector<int> &nums) {
        for (const auto &num : nums) {
            if (max_q.empty() || num < max_q.top())
                max_q.push(num);
            else
                min_q.push(num);

            if (max_q.size() > (min_q.size() + 1)) {
                min_q.push(max_q.top());
                max_q.pop();
            } else if (min_q.size() > max_q.size()) {
                max_q.push(min_q.top());
                min_q.pop();
            }
        }
    }

    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
};

