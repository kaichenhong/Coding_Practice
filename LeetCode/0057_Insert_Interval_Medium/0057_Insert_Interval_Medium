/**
 *  Results:    AC (4 ms [99.88%];  17 MB [92.75%])
 */


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        size_t i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1] ) {
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            ++i;
        }
        res.push_back(newInterval);

        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }
};
