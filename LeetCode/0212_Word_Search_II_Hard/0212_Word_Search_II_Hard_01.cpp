/*
 *  Results:    AC (388 ms [69.70%];  13.6 MB [14.08%])
 */

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> results;

        build_words_trie(words);

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, root_.get(), i, j, results);

        return results;
    }
private:
    struct Position {
        Position() : x(-1), y(-1), used(0) {}
        Position(int i, int j) : x(i), y(j), used(0) {}
        ~Position() {
            x = -1;
            y = -1;
            used = 0;
        }

        int x, y;
        int used;
    };

    struct TrieNode {
        TrieNode() : nodes(26, nullptr) {}
        ~TrieNode() {
            for (struct TrieNode *node : nodes)
                if (node)
                    delete node;
        }

        vector<struct TrieNode*> nodes;
        string word;
    };

    static void dfs(
        vector<vector<char>> &board, struct TrieNode *node,
        const int i, const int j, vector<string> &results)
    {
        char letter;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#')
            return;
        if (!(node && node->nodes[board[i][j]-'a']))
            return;

        node = node->nodes[board[i][j]-'a'];
        if (node->word != "") {
            results.push_back(node->word);
            node->word = "";
        }


        /* mark as be checked */
        letter = board[i][j];
        board[i][j] = '#';

        dfs(board, node, i-1, j, results);
        dfs(board, node, i+1, j, results);
        dfs(board, node, i, j-1, results);
        dfs(board, node, i, j+1, results);

        /* restore board for un-mark */
        board[i][j] = letter;
    }

    void build_words_trie(const vector<string> &words) {
        if (!root_)
            root_ = std::unique_ptr<struct TrieNode>(new TrieNode());

        for (const string word : words) {
            struct TrieNode *ptr = root_.get();

            for (const char c : word) {
                if (!ptr->nodes[c-'a'])
                    ptr->nodes[c-'a'] = new struct TrieNode();

                ptr = ptr->nodes[c-'a'];

                if (!ptr)
                    break;
            }

            ptr->word = word;
        }
    }

    std::unique_ptr<struct TrieNode> root_;
};


