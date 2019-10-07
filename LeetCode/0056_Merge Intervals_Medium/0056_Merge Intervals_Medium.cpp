/**
 *  LeetCode: 56. Jump Game (Medium)
 *
 *     Given a collection of intervals, merge all overlapping intervals.
 *
 *     Note:   Input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 *
 *
 *
 *      Example:    1. [[1,3],[2,6],[8,10],[15,18]] => [[1,6],[8,10],[15,18]]; (Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].)    
 *                  2. [[1,4],[4,5]] => [[1,5]]; (Intervals [1,4] and [4,5] are considered overlapping.)
 *
 *
 *  Results:    AC (16 ms [93.60%];  12.2 MB [100.00%])
 */


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)   return intervals;

        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (results[results.size()-1][1] >= intervals[i][0])
                results[results.size()-1][1] = max(results[results.size()-1][1], intervals[i][1]);
            else
                results.push_back(intervals[i]);
        }

        return results;
    }

private:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
};