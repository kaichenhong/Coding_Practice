/*
 *  Results:    AC (12 ms [99.47%];  13.3 MB [88.79%])
 */


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> table(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> start;
        int numDequeue = 0;

        /* building graph --- adjacency list */
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            table[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        /* find out the node that in-degree is zero */
        /* and add its courseNum into queue */
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                start.push(i);

        while (!start.empty()) {
            int course_num = start.front();

            numDequeue++;
            start.pop();
            for (size_t i = 0; i < table[course_num].size(); ++i) {
                indegree[table[course_num][i]]--;
                if (indegree[table[course_num][i]] == 0)
                    start.push(table[course_num][i]);
            }
        }

        return numCourses == numDequeue;
    }
};


