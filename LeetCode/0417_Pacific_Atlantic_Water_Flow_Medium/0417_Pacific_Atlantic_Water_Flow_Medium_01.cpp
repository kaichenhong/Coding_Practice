/*
 *  Results:    AC (32 ms [98.76%];  18.1 MB [66.31%])
 */


static const int dir_r[4] = {-1, 1,  0, 0};
static const int dir_c[4] = { 0, 0, -1, 1};

static bool chk_boundary(int r, int c, int rows, int cols)
{
    if ((r < 0 || r >= rows) || (c < 0 || c >= cols))
        return false;
    return true;
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int rows = heights.size();
        const int cols = heights[0].size();
        queue<pair<int, int>> p_o, a_o;
        vector<vector<bool>> vis_p(rows, vector<bool>(cols, false));
        vector<vector<bool>> vis_a(rows, vector<bool>(cols, false));
        vector<vector<int>> res;

        for (int i = 0; i < cols; ++i) {
            p_o.push({0, i});
            vis_p[0][i] = true;

            a_o.push({rows-1, i});
            vis_a[rows-1][i] = true;
        }

        for (int i = 0; i < rows-1; ++i) {
            p_o.push({i+1, 0});
            vis_p[i+1][0] = true;

            a_o.push({i, cols-1});
            vis_a[i][cols-1] = true;
        }

        bfs(heights, rows, cols, p_o, vis_p);
        bfs(heights, rows, cols, a_o, vis_a);

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (vis_p[r][c] && vis_a[r][c])
                    res.push_back({r, c});

        return res;
    }

private:
    void bfs(const vector<vector<int>> &heights, int rows, int cols, queue<pair<int, int>> &q, vector<vector<bool>> &vis) {
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            /* mark current location visited */
            // printf("cur:(%d, %d)\n", cur.first, cur.second);
            vis[cur.first][cur.second] = true;
            for (int i = 0; i < 4; ++i) {
                int r = cur.first + dir_r[i];
                int c = cur.second + dir_c[i];

                if (chk_boundary(r, c, rows, cols)
                    && vis[r][c] == false
                    && heights[cur.first][cur.second]
                        <= heights[r][c]) {
                    // insert into the queue and mark visited
                    q.push({r, c});
                    vis[r][c] = true;
                    // printf("push:(%d, %d)\n", r, c);
                }
            }
        }
    }
};

