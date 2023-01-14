/*
 *  Results:    AC (252 ms [64.72%];  78.6 MB [80.49%])
 */


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>> pri_q;
        float latest_arrival_time = 0;
        int fleets = 0;

        for (size_t i = 0; i < position.size(); ++i)
            pri_q.push({position[i], speed[i]});

        while (!pri_q.empty()) {
            const float time = (float)(target - pri_q.top().first) / pri_q.top().second;

            if (time > latest_arrival_time) {
                latest_arrival_time = time;
                fleets++;
            }

            pri_q.pop();
        }

        return fleets;
    }
};

