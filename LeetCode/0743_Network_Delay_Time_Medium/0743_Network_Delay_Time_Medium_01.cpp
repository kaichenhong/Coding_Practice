/*
 *  Results:    AC (75 ms [99.20%];  39.73 MB [92.33%])
 */


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        queue<int> q;
        int dist[n+1];
        int result = 0;

        for (const auto &v : times)
            adj[v[0]].push_back({v[1], v[2]});
        for (unsigned int i = 0 ; i < (n+1); ++i)
            dist[i] = INT_MAX;

        dist[k] = 0;
        q.push(k);
        while (!q.empty()) {
            const unsigned int len = q.size();

            for (unsigned int i = 0; i < len; ++i) {
                const int idx = q.front();

                q.pop();
                for (const auto &node : adj[idx]) {
                    if ((dist[idx] + node.second) < dist[node.first]) {
                        q.push(node.first);
                        dist[node.first] = dist[idx] + node.second;
                    }
                    // printf("at:%d, children:%d, dist:%u\n",
                    //    idx, node.first, dist[node.first]);
                }
            }
        }

        for (unsigned int i = 1; i < (n+1); ++i) {
            if (dist[i] == INT_MAX)
                return -1;
            result = max(result, dist[i]);
        }
        return result;
    }
};

