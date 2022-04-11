/*
 *  Results:    AC (518 ms [71.09%];  89.8 MB [82.96%])
 */


static bool cmp(const vector<int> &v1, const vector<int> &v2)
{
    if (v1[1] == v2[1])
        return (v1[0] > v2[0]);
    return (v1[1] < v2[1]);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), cmp);
        int prev = 0, res = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[prev][1] > intervals[i][0])
                res++;
            else
                prev = i;
        }

        return res;
    }
};

