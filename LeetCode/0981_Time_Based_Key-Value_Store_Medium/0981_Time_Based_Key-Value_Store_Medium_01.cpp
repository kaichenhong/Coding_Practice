/*
 *  Results:    AC (295 ms [98.85%];  128.6 MB [86.73%])
 */


class TimeMap {
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        table[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (table.count(key) == 0)
            return "";

        if (timestamp < table[key].front().second)
            return "";
        if (timestamp >= table[key].back().second)
            return table[key].back().first;

        int l = 0, r = table[key].size() - 1;
        while (l <= r) {
            const int med = (l + r) / 2;

            if (table[key][med].second == timestamp)
                return table[key][med].first;
            if (table[key][med].second < timestamp)
                l = med + 1;
            else
                r = med - 1;
        }

        return (r >= 0) ? table[key][r].first : "";
    }

private:
    unordered_map<string, vector<pair<string,int>>> table;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

