/*
 *  Results:    AC (0 ms [100.00%];  7.6 MB [82.08%])
 */


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        for (const auto &stone : stones)
            max_q.push(stone);

        while (max_q.size() > 1) {
            const int y = max_q.top(); max_q.pop();
            const int x = max_q.top(); max_q.pop();
            if ((y - x) > 0)
                max_q.push(y - x);
        }

        return (max_q.size()) ? max_q.top() : 0;
    }

private:
    priority_queue<int> max_q;
};

