/*
 *  Results:    AC (76 ms [99.02%];  39.91 MB [74.41%])
 */


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<unsigned int, int>, vector<pair<unsigned int, int>>, greater<pair<unsigned int, int>>> pri_q;
        vector<pair<int, int>> adj[n+1];
        queue<int> q;
        int dist[n+1];
        int result = 0;

        for (const auto &v : times)
            adj[v[0]].push_back({v[1], v[2]});
        for (unsigned int i = 0 ; i < (n+1); ++i)
            dist[i] = INT_MAX;

        dist[k] = 0;
        pri_q.push({0, k});
        while (!pri_q.empty()) {
            const pair<unsigned, int> t = pri_q.top();

            pri_q.pop();
            for (const auto &node : adj[t.second]) {
                if ((dist[t.second] + node.second) < dist[node.first]) {
                    dist[node.first] = dist[t.second] + node.second;
                    pri_q.push({dist[node.first], node.first});
                }
                // printf("at:%d, children:%d, dist:%u\n",
                //    t.second, node.first, dist[node.first]);
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

