/*
 *  Results:    AC (299 ms [57.80%];  96.6 MB [13.68%])
 */


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int> car_map;
        float latest_arrival_time = 0;
        int fleets = 0;

        for (size_t i = 0; i < position.size(); ++i)
            car_map[position[i]] = speed[i];

        for (auto car_info = car_map.rbegin(); car_info != car_map.rend(); ++car_info) {
            const float time = (float)(target - car_info->first) / car_info->second;

            if (time > latest_arrival_time) {
                latest_arrival_time = time;
                fleets++;
            }
        }

        return fleets;
    }
};

