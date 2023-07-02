/*
 *  Results:    AC (4 ms [95.61%];  8.7 MB [94.70%])
 */


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init_disjoint_set(edges);
        for (const auto &edge : edges) {
            if (union_by_rank(edge.at(0), edge.at(1)) == false)
                return edge;
        }
        return vector<int>{};
    }
private:
    inline void init_disjoint_set(const vector<vector<int>> &edges) {
        disjoint_set.resize(edges.size()+1);
        for (unsigned int i = 0; i <= edges.size(); ++i) {
            disjoint_set.at(i).first = i;    // parent => init to self.
            disjoint_set.at(i).second = 0;   // rank   => init to zero.
        }
    }
    inline int find_root(const int n) {
        // using path compression
        if (disjoint_set.at(n).first == n)
            return disjoint_set.at(n).first;
        return disjoint_set.at(n).first = find_root(disjoint_set.at(n).first);
    }
    bool union_by_rank(const int x, const int y) {
        const int r_x = find_root(x);
        const int r_y = find_root(y);

        if (r_x == r_y)
            return false;

        if (disjoint_set.at(r_x).second == disjoint_set.at(r_y).second) {
            disjoint_set.at(r_y).first = r_x;
            disjoint_set.at(r_y).second++;
        } else {
            if (disjoint_set.at(r_x).second > disjoint_set.at(r_y).second)
                disjoint_set.at(r_y).first = r_x;
            else
                disjoint_set.at(r_x).first = r_y;
        }

        // printf("edge:(%d, %d) => root:(%d, %d) => (%d, %d), rank:(%d, %d)\n",
        //     x, y, r_x, r_y,
        //     disjoint_set.at(r_x).first, disjoint_set.at(r_y).first,
        //     disjoint_set.at(r_x).second, disjoint_set.at(r_y).second);

        return true;
    }

    // pair<int, int> = <parent. rank>
    vector<pair<int, int>> disjoint_set;
};

