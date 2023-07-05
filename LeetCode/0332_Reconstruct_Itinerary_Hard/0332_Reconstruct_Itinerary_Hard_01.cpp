/*
 *  Results:    AC (16 ms [95.19%];  14.5 MB [60.59%])
 */


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        init_tickets_table(tickets);
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
private:
    void dfs(string vtex) {
        auto &edges = table[vtex];

        while (!edges.empty()) {
            string to_vtex = edges.top();

            edges.pop();
            dfs(to_vtex);
        }
        result.push_back(vtex);
    }
    inline void init_tickets_table(const vector<vector<string>> &tickets) {
        for (const vector<string> &ticket : tickets)
            table[ticket[0]].push(ticket[1]);
    }

    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> table;
    vector<string> result;
};

