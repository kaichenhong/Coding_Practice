/*
 *  Results:    AC (20 ms [71.11%];  23.7 MB [51.50%])
 */


const static int direction[5][2] = {
    {0, 0},   // origin
    {0, 1},   // right
    {1, 0},   // down
    {-1, 0},  // up
    {0, -1},  // left
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (setup_grid_info(grid))
            return 0;

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                find_max_area(i, j, grid);

        return max_area;
    }
private:
    inline int check_grid_boundary(int &i, int &j, const size_t dir) {
        // printf("size:(r:%u, c:%u), (%d, %d), dir:%u(%d, %d)\n",
        //   rows, cols, i, j, dir, direction[dir][0], direction[dir][1]);

        i += direction[dir][0];
        j += direction[dir][1];

        if (!(0 <= i && i < rows) || !(0 <= j && j < cols))
            return -1;
        return 0;
    }

    void find_4direct_connected(int i, int j, const size_t dir, int &area, vector<vector<int>> &grid) {
        if (check_grid_boundary(i, j, dir) || grid.at(i).at(j) != 1)
            return;

        ++area;
        grid.at(i).at(j) = -1;
        for (size_t k = 1; k < 5; ++k)
            find_4direct_connected(i, j, k, area, grid);
    }

    void find_max_area(int i, int j, vector<vector<int>> &grid) {
        int area = 0;

        find_4direct_connected(i, j, 0, area, grid);
        max_area = max(max_area, area);
    }

    int setup_grid_info(const vector<vector<int>> &grid) {
        rows = grid.size();
        if (rows == 0)
            return -1;
        cols = grid.at(0).size();
        return 0;
    }

    size_t rows;
    size_t cols;
    int max_area;
};

