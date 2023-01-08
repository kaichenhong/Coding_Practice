/*
 *  Results:    AC (190 ms [96.84%];  103.1 MB [41.02%])
 */


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());

        for (unsigned int i = 0; i < temperatures.size(); ++i) {
            while (!idx_st.empty() && temperatures[idx_st.top()] < temperatures[i]) {
                result[idx_st.top()] = i - idx_st.top();
                idx_st.pop();
            }
            idx_st.push(i);
        }

        return result;
    }

private:
    stack<unsigned int> idx_st;
};

