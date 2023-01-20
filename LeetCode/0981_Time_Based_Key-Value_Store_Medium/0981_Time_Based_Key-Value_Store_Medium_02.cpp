/*
 *  Results:    AC (321 ms [91.66%];  131.1 MB [31.88%])
 */


class TimeMap {
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        table[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto iter = table[key].upper_bound(timestamp);

        if (iter == table[key].begin())
            return "";
        return (--iter)->second;
    }

private:
    unordered_map<string, map<int,string>> table;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

