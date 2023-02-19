/*
 *  Results:    AC (58 ms [96.16%];  34.4 MB [94.67%])
 */


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> table(26);
        int needed_idle_slots;

        for (const auto &task : tasks)
            table[task - 'A']++;
        std::sort(table.begin(), table.end());
        needed_idle_slots = n * (table[25] - 1);

        for (int i = 24; i >= 0; --i) {
            if (table[i] == 0)
                break;
            needed_idle_slots -= std::min(table[i], (table[25] - 1));
        }

        return (needed_idle_slots > 0)
            ? (tasks.size() + needed_idle_slots) : (tasks.size());
    }
};

// e.g., tasks = ["A","A","A","B","B","B"], n = 2;
/*
1 2 3 4 5 6 7 8
=============
A _ _ A _ _ A
=>
A B _ A B _ A B
*/

// e.g., tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2;
/*
A:6, B:1, C:1, D:1, E:1, F:1, G:1
1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
===============================
A _ _ A _ _ A _ _ A _ _ A _ _ A
=>
A B C A D E A F G A _ _ A _ _ A
*/

