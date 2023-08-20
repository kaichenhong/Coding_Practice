/*
 *  Results:    AC (333 ms [100.00%];  110.03 MB [90.48%])
 */


class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const unsigned int q_len = queries.size();
        const unsigned int i_len = intervals.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pri_q;
        vector<pair<int, unsigned int>> q_set(q_len);
        vector<int> res(q_len, -1);

        sort(intervals.begin(), intervals.end());
        for (unsigned int i = 0; i < q_len; ++i)
            q_set[i] = {queries[i], i};
        sort(q_set.begin(), q_set.end());

        for (unsigned int i = 0, j = 0; i < q_len; ++i) {
            /* pick up valid intervals into priority queue and sort by range size */
            while (j < i_len && (intervals[j][0] <= q_set[i].first)) {
                pri_q.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                j++;
            }
            /* remove intervals that not match or nerver be considered */
            while (!pri_q.empty() && pri_q.top().second < q_set[i].first)
                pri_q.pop();

            if (!pri_q.empty())
                res[q_set[i].second] = pri_q.top().first;
        }

        return res;
    }
};

