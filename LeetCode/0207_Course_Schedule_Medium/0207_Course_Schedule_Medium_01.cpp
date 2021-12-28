/*
 *  Results:    AC (136 ms [5.00%];  17.8 MB [5.44%])
 */


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> table(prerequisites.size());

        for (size_t i = 0; i < prerequisites.size(); ++i)
            table[prerequisites[i][0]].insert(prerequisites[i][1]);

        for (int i = 0; i < numCourses; ++i) {
            vector<bool> visited(numCourses, 0);
            if (!dfs(i, i, table, visited))
                return false;
        }

        return true;
    }
private:
    bool dfs(int start, int curr, const unordered_map<int, unordered_set<int>> &table, vector<bool> &visited) {
        if (start == curr && visited[start])
            return false;

        if (!table.count(curr))
            return true;

        for (const int iter : table.at(curr)) {
            if (visited[iter])
                continue;

            visited[iter] = true;
            if (!dfs(start, iter, table, visited))
                return false;
        }

        return true;
    }
};

