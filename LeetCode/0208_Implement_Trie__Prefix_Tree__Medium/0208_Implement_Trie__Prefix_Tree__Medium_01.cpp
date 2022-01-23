/*
 *  Results:    AC (76 ms [58.19%];  50.2 MB [11.97%])
 */


class Trie {
public:
    Trie() {
        root = std::unique_ptr<struct TrieNode>(new TrieNode());
    }

    void insert(string word) {
        struct TrieNode *ptr = root.get();

        for (const char c : word) {
            if (ptr->nodes[c-'a'] == nullptr)
                ptr->nodes[c-'a'] = new TrieNode();
            ptr = ptr->nodes[c-'a'];
        }

        ptr->eol = true;
    }

    bool search(string word) {
        const struct TrieNode *ptr = find(word);

        return (ptr && ptr->eol);
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
private:
    struct TrieNode {
        TrieNode():eol(false), nodes(26, nullptr){}
        ~TrieNode() {
            for (struct Trieode *node : nodes)
                if (node)
                    delete(node);
        }

        vector<struct TrieNode*> nodes;
        bool eol;
    };

    struct TrieNode* find(const string &word) const {
        struct TrieNode *ptr = root.get();

        for (const char c : word) {
            ptr = ptr->nodes[c-'a'];
            if (!ptr)
                break;
        }
        return ptr;
    }

    std::unique_ptr<struct TrieNode> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

