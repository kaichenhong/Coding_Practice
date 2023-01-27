/*
 *  Results:    AC (34 ms [84.60%];  20.0 MB [45.85%])
 */


class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        len = k;
        for (const auto &num : nums) {
            min_q.push(num);
            len--;
        }
        while (len < 0) {
            min_q.pop();
            len++;
        }
    }

    int add(int val) {
        min_q.push(val);
        len--;
        while (len < 0) {
            min_q.pop();
            len++;
        }
        return min_q.top();
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> min_q;
    int len;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

