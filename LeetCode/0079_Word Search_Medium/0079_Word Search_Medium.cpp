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
 *  Results:    AC (252 ms [33.88%];  155.1 MB [33.82%])
 */


static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.size() == 0)  return false;

        for (size_t r = 0; r < board.size(); ++r) {
            for (size_t c = 0; c < board[0].size(); ++c) {
                if (solver_dfs(board, word, r, c, 0))   
                    return true;
            }
        }
        return false;
    }

private: 
    bool solver_dfs(vector<vector<char>>& board, string word, size_t r, size_t c, size_t idx) {
        if (idx == word.size())   return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || 
            board[r][c] != word[idx])    return false;

        char buff = board[r][c];
        board[r][c] = ' ';

        bool result = solver_dfs(board, word, r-1, c, idx+1) ||
                      solver_dfs(board, word, r+1, c, idx+1) ||
                      solver_dfs(board, word, r, c-1, idx+1) ||
                      solver_dfs(board, word, r, c+1, idx+1) ;
        
        board[r][c] = buff;

        return result;
    }
};