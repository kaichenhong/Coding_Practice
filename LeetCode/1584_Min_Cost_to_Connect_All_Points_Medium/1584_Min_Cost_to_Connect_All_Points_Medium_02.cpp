/*
 *  Results:    AC (342 ms [70.78%];  31.70 MB [88.33%])
 */


class DSU {
public:
    DSU(const unsigned int n) {
        parent.resize(n);
        rank.resize(n);
        for (unsigned int i = 0; i < n; ++i)
            parent[i] = i;
    }
    unsigned int find(const unsigned int node) {
        // printf("node:%u, parent:%u\n", node, parent[node]);
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    bool union_by_rank(const unsigned int a, const unsigned int b) {
        const unsigned int root_a = find(a);
        const unsigned int root_b = find(b);

        if (root_a == root_b)
            return false;

        if (rank[root_a] < rank[root_b])
            parent[root_a] = root_b;
        else if (rank[root_a] > rank[root_b])
            parent[root_b] = root_a;
        else {
            parent[root_a] = root_b;
            rank[root_b]++;
        }
        // printf("- a:%u(root:%u/rank:%u/parent:%u), b:%u(root:%u/rank:%u/parent:%u)\n",
        //    a, root_a, rank[root_a], parent[root_a],
        //    b, root_b, rank[root_b], parent[root_b]);
        return true;
    }
private:
    vector<unsigned int> parent;
    vector<unsigned int> rank;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const unsigned int n = points.size();
        vector<pair<unsigned int, pair<unsigned int, unsigned int>>> adjacency(n * (n + 1) / 2 - n);
        DSU dsu(n);
        unsigned int k = 0;
        int cost = 0;

        for (unsigned int i = 0; i < n; ++i) {
            for (unsigned int j = (i + 1); j < n; ++j) {
                adjacency[k++] =
                    {abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}};
            }
        }
        sort(adjacency.begin(), adjacency.end());
        for (const auto &adj : adjacency) {
            const unsigned int val = adj.first;
            const auto [p1, p2] = adj.second;

            // printf("p1:%u:(%d,%d), p2:%u:(%d,%d), val:%u\n",
            //    p1, points[p1][0], points[p1][1], p2, points[p2][0], points[p2][1], val);
            if (dsu.union_by_rank(p1, p2))
                cost += val;
        }

        return cost;
    }
};

