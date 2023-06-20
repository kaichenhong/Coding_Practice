/*
 *  Results:    AC (11 ms [99.87%];  13.5 MB [70.64%])
 */


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;

        graph_info_builder(numCourses, prerequisites);
        return (topological_sort(numCourses, res)) ? res : vector<int>{};
    }
private:
    bool topological_sort(const int numCourses, vector<int> &res) {
        queue<int> q;
        int cnt = 0;

        for (unsigned int i = 0; i < numCourses; ++i)
            if (indegree.at(i) == 0)
                q.push(i);

        while (!q.empty()) {
            const int course = q.front();

            res.push_back(course);
            for (const auto &iter : graph.at(course)) {
                indegree.at(iter)--;
                if (indegree.at(iter) == 0)
                    q.push(iter);
            }
            cnt++;
            q.pop();
        }

        /* checking if it is DAG */
        return (cnt == numCourses) ? true : false;
    }

    inline void graph_info_builder(const int numCourses, const vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        indegree.resize(numCourses);

        for (const auto &iter : prerequisites) {
            graph.at(iter.at(1)).push_back(iter.at(0));
            indegree.at(iter.at(0))++;
        }
    }

    vector<vector<int>> graph;
    vector<int> indegree;
};

