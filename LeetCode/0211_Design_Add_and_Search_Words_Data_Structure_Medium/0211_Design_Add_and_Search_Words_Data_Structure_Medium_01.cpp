/*
 *  Results:    AC (72 ms [86.75%];  46.7 MB [35.82%])
 */


class WordDictionary {
public:
    WordDictionary() {
        root = std::unique_ptr<struct TrieNode>(new struct TrieNode());
    }

    void addWord(string word) {
        struct TrieNode *ptr = root.get();

        for (const char c : word) {
            if (!ptr->nodes[c-'a'])
                ptr->nodes[c-'a'] = new struct TrieNode();
            ptr = ptr->nodes[c-'a'];
        }

        ptr->eol = true;
    }

    bool search(string word) {
        return dfs(word, root.get(), 0);
    }
private:
    struct TrieNode {
        TrieNode():eol(false), nodes(26, nullptr) {}
        ~TrieNode() {
            for (struct TrieNode *node : nodes)
                if (node)
                    delete node;
        }

        vector<struct TrieNode*> nodes;
        bool eol;
    };

    bool dfs(const string &word, const struct TrieNode *ptr, const unsigned int idx) {
        if (!ptr)
            return false;
        if (idx >= word.size())
            return ptr->eol;

        char c = word[idx];

        if (c == '.') {
            for (const struct TrieNode *p_iter : ptr->nodes)
                if (dfs(word, p_iter, idx+1))
                    return true;
            return false;
        } else
            return dfs(word, ptr->nodes[c-'a'], idx+1);
    }

    std::unique_ptr<struct TrieNode> root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

