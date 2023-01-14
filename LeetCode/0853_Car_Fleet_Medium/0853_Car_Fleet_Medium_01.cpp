/*
 *  Results:    AC (174 ms [99.92%];  74.0 MB [96.18%])
 */


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> info_sets;
        const size_t n = position.size();
        float latest_arrival_time = 0;
        int fleets = 0;

        info_sets.reserve(n);
        for (size_t i = 0; i < n; ++i)
            info_sets.push_back({position[i], speed[i]});

        sort(info_sets.begin(), info_sets.end(), [](auto a, auto b){return a.first > b.first;});

        for (size_t i = 0; i < n; ++i) {
            const float time = (float)(target - info_sets.at(i).first) / info_sets.at(i).second;

            if (time > latest_arrival_time) {
                latest_arrival_time = time;
                fleets++;
            }
        }

        return fleets;
    }
};

