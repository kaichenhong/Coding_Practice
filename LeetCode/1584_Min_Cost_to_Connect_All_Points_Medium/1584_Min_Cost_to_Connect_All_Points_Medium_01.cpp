/*
 *  Results:    AC (74 ms [96.21%];  13.71 MB [91.30%])
 *  Results:    AC (531 ms [59.28%];  41.98 MB [87.41%])
 */


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const unsigned int n = points.size();
        priority_queue<pair<unsigned int, unsigned int>, vector<pair<unsigned int, unsigned int>>, greater<pair<unsigned int, unsigned int>>> min_heap;
        vector<int> dist(n, INT_MAX);
        bool visited[n];
        int cost = 0, cnt = 0;

        memset(visited, 0, sizeof(visited));
        min_heap.push({0, 0});
        while (!min_heap.empty()) {
            auto [curr_cost, idx] = min_heap.top();

            min_heap.pop();
            if (visited[idx])
                continue;
            visited[idx] = true;
            cost += curr_cost;
            if (++cnt == n)
                return cost;

            for (unsigned int i = 0; i < n; ++i) {
                const unsigned int tmp =
                        abs(points[idx][0] - points[i][0]) +
                        abs(points[idx][1] - points[i][1]);

                if (!visited[i] && dist[i] > tmp) {
                    dist[i] = tmp;
                    min_heap.push({tmp, i});
                }
            }
        }

        return cost;
    }
};

#if 0
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const unsigned int n = points.size();
        priority_queue<pair<unsigned int, unsigned int>, vector<pair<unsigned int, unsigned int>>, greater<pair<unsigned int, unsigned int>>> min_heap;
        bool visited[n];
        int cost = 0;

        memset(visited, 0, sizeof(visited));
        min_heap.push({0, 0});
        while (!min_heap.empty()) {
            auto [curr_cost, idx] = min_heap.top();

            min_heap.pop();
            if (visited[idx])
                continue;
            visited[idx] = true;
            cost += curr_cost;
            for (unsigned int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    const unsigned int dist =
                        abs(points[idx][0] - points[i][0]) +
                        abs(points[idx][1] - points[i][1]);

                    min_heap.push({dist, i});
                }
            }
        }

        return cost;
    }
};
#endif

