/*
 *  Results:    AC (228 ms [81.94%];  63.3 MB [75.03%])
 */


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        for (const auto &point : points) {
            const int pow_dist = point[0] * point[0] + point[1] * point[1];
            que.push({pow_dist, {point[0], point[1]}});
            if (que.size() > k)
                que.pop();
        }

        for (int i = 0; i < k; ++i) {
            const auto point = que.top().second; que.pop();
            result.push_back({point.first, point.second});
        }

        return result;
    }

private:
    priority_queue<pair<int, pair<int, int>>> que;
};

