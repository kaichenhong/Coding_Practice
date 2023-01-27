/*
 *  Results:    AC (109 ms [86.85%];  47.3 MB [46.84%])
 */


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (const auto &num : nums) {
            if (min_q.size() < k) {
                min_q.push(num);
                continue;
            }
            if (num > min_q.top()) {
                min_q.pop();
                min_q.push(num);
            }
        }
        return min_q.top();
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> min_q;
};

