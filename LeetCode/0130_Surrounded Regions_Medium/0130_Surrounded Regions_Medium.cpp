/**
 *  LeetCode: 130. Surrounded Regions (Medium)
 *
 *      Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *
 *      A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 *
 *
 *      Example:    1.  X X X X         X X X X
 *                      X O O X    =>   X X X X
 *                      X X O X         X X X X
 *                      X O X X         X O X X
 *
 *
 *
 *  Results:    AC (16 ms [99.97%];  13.8 MB [100.00%])
 */


static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())   return;
        
        height = int(board.size());
        width = int(board[0].size());

		searchBorderDFS(board);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == 'O')   board[i][j] = 'X';
                if (board[i][j] == '$')   board[i][j] = 'O';
            }
        }
    }

private:
	int height = 0;
	int width = 0;

    void searchBorderDFS(vector<vector<char>> &board) {
        // top-left -> top-right.
        for (int i = 0; i < width; ++i) {
            if (board[0][i] == 'O') {
                solveDFS(0, i, board);
            }
        }
		// top-right -> bottom-right.
        for (int i = 1; i < height; ++i) {
            if (board[i][width-1] == 'O') {
                solveDFS(i, width-1, board);
            }
        }
		// bottom-right -> bottom-left.
        for (int i = width-2; i >= 0; --i) {
            if (board[height-1][i] == 'O') {
                solveDFS(height-1, i, board);
            }
        }
		// bottom-left -> top-left.
        for (int i = height-2; i >= 0; --i) {
            if (board[i][0] == 'O') {
                solveDFS(i, 0, board);
            }
        }
    }

    void solveDFS(int i, int j, vector<vector<char>> &board) {
        if (i < 0 || i >= height || 
			j < 0 || j >= width || 
			board[i][j] == 'X' || board[i][j] == '$') 
		{
			return;
		}
		if (board[i][j] == 'O') {
			board[i][j] = '$';
		}
		solveDFS(i-1, j, board);
		solveDFS(i+1, j, board);
		solveDFS(i, j-1, board);
		solveDFS(i, j+1, board);
    }
};