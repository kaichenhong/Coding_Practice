/*
 *  Results:    AC (26 ms [99.88%];  13.5 MB [96.22%])
 */


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> top_q, bottom_q;
        unordered_set<string> *forward_q_ptr, *target_q_ptr;
        unsigned int step = 0;

        dict = unordered_set<string>(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0)
            return 0;

        top_q.insert(beginWord);
        bottom_q.insert(endWord);
        while (!top_q.empty() && !bottom_q.empty()) {
            unordered_set<string> buf_q;

            // choose the smallest queue/set first
            forward_q_ptr = (top_q.size() < bottom_q.size()) ? &top_q : &bottom_q;
            target_q_ptr = (forward_q_ptr == &top_q) ? &bottom_q : &top_q;

            step++;
            for (string word : *forward_q_ptr) {
                for (char &c_iter : word) {
                    char orig = c_iter;

                    for (char j = 'a'; j <= 'z'; ++j) {
                        c_iter = j;
                        if (target_q_ptr->count(word) != 0)
                            return (step + 1);
                        if (dict.count(word) != 0) {
                            dict.erase(word);
                            buf_q.insert(word);
                        }
                    }
                    c_iter = orig;
                }
            }
            // std::swap(*forward_q_ptr, buf_q);
            forward_q_ptr->swap(buf_q);
        }
        return 0;
    }
private:
    unordered_set<string> dict;
};

