/*
 *  Results:    AC (103 ms [61.31%];  13.6 MB [94.77%])
 */


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unsigned int step = 0;
        queue<string> q;

        dict = unordered_set<string>(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0)
            return 0;

        q.push(beginWord);
        while (!q.empty()) {
            const unsigned int q_step_size = q.size();

            step++;
            for (unsigned int i = 0; i < q_step_size; ++i) {
                string word = q.front();

                for (char &c_iter : word) {
                    char backup = c_iter;

                    for (char j = 'a'; j <= 'z'; ++j) {
                        c_iter = j;
                        if (word == endWord)
                            return (step + 1);
                        if (dict.count(word) == 0)
                            continue;
                        dict.erase(word);
                        q.push(word);
                    }
                    c_iter = backup;
                }
                q.pop();
            }
        }
        return 0;
    }
private:
    unordered_set<string> dict;
};

