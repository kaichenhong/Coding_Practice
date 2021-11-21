/**
 *  LeetCode: 79. Word Search (Medium)
 *
 *      Given a 2D board and a word, find if the word exists in the grid.
 *
 *      The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
 *
 *      The same letter cell may not be used more than once.
 *
 *
 *
 *      Example:    1.  board = [ ['A','B','C','E'], ['S','F','C','S'], ['A','D','E','E'] ]     =>      Given word = "ABCCED", return true.
 *                                                                                                      Given word = "SEE", return true.
 *                                                                                                      Given word = "ABCB", return false.
 *
 *
 *
 *  Results:    AC (220 ms [75.58%];  7.8 MB [20.28%])
 */


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (size_t i = 0; i < board.size(); ++i)
            for (size_t j = 0; j < board[i].size(); ++j)
                if (dfs(board, word, i, j))
                    return true;

        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, const string &word, size_t i, size_t j) {
        bool res = false;

        if (word.size() == 0)
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#' || board[i][j] != word[0])
            return false;

        const char restore = board[i][j];
        const string sub = word.substr(1);

        board[i][j] = '#';
        res = dfs(board, sub, i-1, j)
            | dfs(board, sub, i, j+1)
            | dfs(board, sub, i+1, j)
            | dfs(board, sub, i, j-1);
        board[i][j] = restore;

        return res;
    }
};

