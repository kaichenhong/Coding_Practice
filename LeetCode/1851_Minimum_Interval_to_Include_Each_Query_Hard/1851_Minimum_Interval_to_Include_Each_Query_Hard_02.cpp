/*
 *  Results:    AC (420 ms [85.26%];  122.40 MB [45.71%])
 */


class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const unsigned int q_len = queries.size();
        set<pair<int, unsigned int>> q_set;
        vector<int> res(q_len, -1);

        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return (a[1] - a[0]) < (b[1] - b[0]);
        });
        for (unsigned int i = 0; i < q_len; ++i)
            q_set.insert({queries[i], i});

        for (const auto & interval : intervals) {
            auto iter_l = q_set.lower_bound({interval[0], 0});
            auto iter_r = q_set.upper_bound({interval[1], q_len});

            while (iter_l != iter_r) {
                // printf("interval:[%d ~ %d], iter_l:(idx:%u, val:%d) <=> iter_r:(idx:%u, val:%d)\n",
                //    interval[0], interval[1],
                //    iter_l->second, iter_l->first,
                //    iter_r->second, iter_r->first);

                res[iter_l->second] = interval[1] - interval[0] + 1;
                q_set.erase(iter_l++);
                if (q_set.empty())
                    return res;
            }
        }

        return res;
    }
};

