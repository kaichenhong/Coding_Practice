/*
 *  Results:    AC (422 ms [97.54%];  165.1 MB [72.53%])
 */


class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (table.count(key) == 0)
            return -1;
        lru_list.splice(lru_list.begin(), lru_list, table[key].first);
        return table[key].second;
    }

    void put(int key, int value) {
        if (table.count(key) != 0) {
            table[key].second = value;
            lru_list.splice(lru_list.begin(), lru_list, table[key].first);
        } else {
            lru_list.push_front(key);
            table[key] = {lru_list.begin(), value};
            capacity--;

            if (capacity < 0) {
                table.erase(lru_list.back());
                lru_list.pop_back();
                capacity++;
            }
        }
    }

private:
    list<int> lru_list;
    unordered_map<int, pair<list<int>::iterator, int>> table;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

