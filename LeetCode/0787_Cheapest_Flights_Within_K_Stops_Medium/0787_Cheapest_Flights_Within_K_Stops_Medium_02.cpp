/*
 *  Results:    AC (22 ms [59.74%];  12.28 MB [100.00%])
 */


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int min_cost[n];
        int tmp[n];

        for (unsigned int i = 0; i < n; ++i)
            min_cost[i] = INT_MAX;
        min_cost[src] = 0;

        for (int i = 0; i < (k + 1); ++i) {
            memcpy(tmp, min_cost, sizeof(tmp));
            for (const auto &flight : flights) {
                if (min_cost[flight[0]] != INT_MAX)
                    tmp[flight[1]] = min(tmp[flight[1]], min_cost[flight[0]] + flight[2]);
            }
            memcpy(min_cost, tmp, sizeof(tmp));
        }

        return (min_cost[dst] == INT_MAX) ? -1 : min_cost[dst];
    }
};

/*
[0]
 |  \
[1] - [2] - [3]
*/

