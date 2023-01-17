/*
 *  Results:    AC (40 ms [95.00%];  18.8 MB [96.89%])
 */


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /* as problem constraints */
        unsigned int min = 1, max = 1000000000;

        while (min < max) {
            const unsigned int speed = (min + max) / 2;
            unsigned int total_h = 0;

            for (auto &n : piles)
                total_h += (n + speed - 1) / speed;

            if (total_h > h)
                min = speed + 1;
            else
                max = speed;
        }

        return min;
    }
};

