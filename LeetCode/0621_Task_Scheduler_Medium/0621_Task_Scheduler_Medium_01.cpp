/*
 *  Results:    AC (111 ms [45.99%];  44.0 MB [11.75%])
 */


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int times = 0;

        for (const auto &task : tasks)
            table[task]++;
        for (const auto &iter : table)
            pq.push(iter.second);

        while (!pq.empty()) {
            vector<int> process_task;

            for (unsigned int i = 0; i <= n; ++i) {
                if (!pq.empty()) {
                    process_task.push_back(pq.top());
                    pq.pop();
                }
            }

            for (int i = process_task.size() - 1; i >= 0; --i) {
                if (--process_task[i] > 0)
                    pq.push(process_task[i]);
            }

            times += pq.empty() ? process_task.size() : (n + 1);
        }

        return times;
    }

private:
    unordered_map<char,int> table;
    priority_queue<int> pq;
};

