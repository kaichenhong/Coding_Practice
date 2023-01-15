/*
 *  Results:    AC (167 ms [93.53%];  77.1 MB [76.91%])
 */


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        const size_t n = heights.size();
        int max_area = 0;

        for (size_t i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                const int idx = s.top(); s.pop();
                const int area = heights[idx] * ((!s.empty()) ? (i - s.top() - 1) : i);

                max_area = (area > max_area) ? area : max_area;
            }
            s.push(i);
        }

        while (!s.empty()) {
            const int idx = s.top(); s.pop();
            const int area = heights[idx] * ((!s.empty()) ? (n - s.top() - 1) : n);

            max_area = (area > max_area) ? area : max_area;
        }

        return max_area;
    }
};

