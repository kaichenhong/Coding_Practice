/*
 *  Results:    AC (7 ms [99.19%];  8.74 MB [90.58%])
 */


const int dir_row[] = {0, 1, -1, 0};
const int dir_col[] = {1, 0, 0, -1};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const unsigned int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
        int ret = -1;

        min_heap.push({grid[0][0], {0, 0}});
        grid[0][0] = -1;
        while (!min_heap.empty()) {
            const auto pt = min_heap.top();
            const int val = pt.first;
            const auto [row, col] = pt.second;

            min_heap.pop();

            ret = max(ret, val);
            // printf("at:[%d][%d] = %d, ret:%d\n",
            //    row, col, val, ret);
            if (row == n - 1 && col == n -1)
                return ret;

            for (int i = 0; i < 4; ++i) {
                const int r = row + dir_row[i];
                const int c = col + dir_col[i];

                if ((chk_boundary_valid(r, c, n) == false) || (grid[r][c] == -1))
                    continue;

                min_heap.push({grid[r][c], {r, c}});
                // printf("==> push:[%d][%d] = %d\n",
                //    r, c, grid[r][c]);
                grid[r][c] = -1;
            }
        }

        return -1;
    }
private:
    inline bool chk_boundary_valid(const int row, const int col, const unsigned int n) {
        return ((0 <= row && row < n) && (0 <= col && col < n)) ? true : false;
    }
};

