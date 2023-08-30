/*
 *  Results:    AC (13 ms [94.73%];  13.0 MB [90.87%])
 */


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        queue<pair<int, int>> q;
        int min_cost[n];

        for (const auto &flight : flights)
            adj[flight[0]].push_back({flight[1], flight[2]});
        for (unsigned int i = 0; i < n; ++i)
            min_cost[i] = INT_MAX;

        q.push({src, 0});
        while (!q.empty() && (k-- >= 0)) {
            const unsigned int len = q.size();

            for (unsigned int i = 0; i < len; ++i) {
                const auto &[node, curr_cost] = q.front();

                for (const auto &[to_node, price] : adj[node]) {
                    int total_cost = curr_cost + price;

                    if (total_cost < min_cost[to_node]) {
                        min_cost[to_node] = total_cost;
                        q.push({to_node, total_cost});
                    }
                }
                q.pop();
            }
        }

        return (min_cost[dst] == INT_MAX) ? -1 : min_cost[dst];
    }
};

#ifdef PRI_Q // time limit exceeded
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pri_q;
        vector<pair<int, int>> adj[n];

        for (unsigned int i = 0; i < flights.size(); ++i)
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});

        pri_q.push({0, src, k});
        while (!pri_q.empty()) {
            const unsigned int len = pri_q.size();

            for (unsigned int i = 0; i < len; ++i) {
                const auto tmp = pri_q.top();
                const int cost = tmp[0];
                const int curr = tmp[1];
                const int stops = tmp[2];

                pri_q.pop();
                if (curr == dst)
                    return cost;
                if (stops >= 0) {
                    for (const auto &sel : adj[curr]) {
                        pri_q.push({cost + sel.second, sel.first, stops - 1});

                        // printf("at:%d, push:%d, cost:%d, k:%d\n",
                        //    curr, sel.first, cost + sel.second, stops - 1);
                    }
                }
            }
        }

        return -1;
    }
};
#endif

/*
[0]
 |  \
[1] - [2] - [3]
*/

