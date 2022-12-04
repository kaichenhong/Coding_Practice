/*
 *  Results:    AC (20 ms [95.05%];  18.3 MB [57.27%])
 */


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<10>> rows(9), cols(9), blocks(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                // check if there exist this number in the row, col, block.
                if (rows[i][num] || cols[j][num]
                        || blocks[((i/3)*3+(j/3))][num])
                    return false;

                // set this number.
                rows[i].set(num);
                cols[j].set(num);
                blocks[((i/3)*3+(j/3))].set(num);
            }
        }

        return true;
    }
};

