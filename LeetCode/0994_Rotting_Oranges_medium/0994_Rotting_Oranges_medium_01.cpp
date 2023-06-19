/*
 *  Results:    AC (0 ms [100.00%];  13.0 MB [95.47%])
 */


const static int direction[4][2] = {
    {0, 1},  // right
    {1, 0},  // down
    {-1, 0}, // up
    {0, -1}, // left
};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        if (setup_grid_info(grid))
            return -1;
        if (setup_orange_info(grid, q) == 0)
            return 0;

        minute = -1;
        while (!q.empty()) {
            int q_size = q.size();

            while (q_size--)
                find_4dir_adjacent_fresh_orange(grid, q);
            minute++;
        }

        return (fresh_orange_cnt) ? (-1) : minute;
    }
private:
    inline void find_4dir_adjacent_fresh_orange(vector<vector<int>> &grid, queue<pair<int, int>> &q) {
        const auto &locale = q.front();
        int r, c;

        for (unsigned int dir = 0; dir < 4; ++dir) {
            r = locale.first + direction[dir][0];
            c = locale.second + direction[dir][1];
            if ((0 <= r && r < rows) && (0 <= c && c < cols) && grid.at(r).at(c) == 1) {
                q.push(pair(r, c));
                grid.at(r).at(c) = 2;    // => change to rotten
                fresh_orange_cnt--;
            }
        }
        q.pop();
    }

    inline int setup_orange_info(const vector<vector<int>> &grid, queue<pair<int, int>> &q) {
        for (unsigned int i = 0; i < rows; ++i)
            for (unsigned int j = 0; j < cols; ++j) {
                if (grid.at(i).at(j) == 2)
                    q.push(pair(i, j));
                else if (grid.at(i).at(j) == 1)
                    fresh_orange_cnt++;
            }
        return fresh_orange_cnt;
    }

    inline int setup_grid_info(const vector<vector<int>> &grid) {
        rows = grid.size();
        if (rows == 0)
            return -1;
        cols = grid.at(0).size();
        return 0;
    }

    unsigned int rows;
    unsigned int cols;
    int fresh_orange_cnt;
    int minute;
};

