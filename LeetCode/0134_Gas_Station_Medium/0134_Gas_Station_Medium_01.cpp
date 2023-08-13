/*
 *  Results:    AC (93 ms [99.80%];  128.1 MB [47.69%])
 */


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const unsigned int len = gas.size();
        int start_idx = 0, total_gas = 0, start_curr_gas = 0;

        for (unsigned int i = 0; i < len; ++i) {
            const int diff = gas[i] - cost[i];

            total_gas += diff;
            start_curr_gas += diff;
            if (start_curr_gas < 0) {
                start_idx = (i + 1) % len;
                start_curr_gas = 0;
            }
        }

        return (total_gas >= 0) ? start_idx : -1;
    }
};

