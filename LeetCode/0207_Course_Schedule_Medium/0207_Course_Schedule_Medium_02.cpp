/*
 *  Results:    AC (37 ms [25.73%];  14.7 MB [25.46%])
 */


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> table(numCourses);
        vector<bool> checked(numCourses, false);

        /* building graph --- adjacency list */
        for (size_t i = 0; i < prerequisites.size(); ++i)
            table[prerequisites[i][1]].push_back(prerequisites[i][0]);

        /* DFS checking */
        for (int i = 0; i < numCourses; ++i) {
            vector<bool> visited(numCourses, false);
            if (!dfs(i, table, visited, checked))
                return false;
        }

        return true;
    }
private:
    bool dfs(int idx, vector<vector<int>> &table, vector<bool> &visited, vector<bool> &checked) {
        if (checked[idx])
            return true;
        if (visited[idx])
            return false;

        visited[idx] = true;

        for (size_t i = 0; i < table[idx].size(); ++i)
            if (!dfs(table[idx][i], table, visited, checked))
                return false;

        visited[idx] = false;
        checked[idx] = true;

        return true;
    }
};


