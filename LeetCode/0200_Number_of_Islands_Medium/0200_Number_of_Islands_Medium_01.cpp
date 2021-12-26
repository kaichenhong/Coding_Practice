/*
 *  Results:    AC (24 ms [99.18%];  12.2 MB [97.23%])
 */


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;

        for (size_t i = 0; i < grid.size(); ++i)
            for (size_t j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }

        return cnt;
    }
private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if ((i < 0 || i >= grid.size()) || (j < 0 || j >= grid[0].size()) || grid[i][j] != '1')
            return;

        grid[i][j] = '0';

        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};

