/*
 *  Results:    AC (12 ms [96.19%];  19.8 MB [83.52%])
 */


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;

        while (l < r) {
            int lower = height[height[l] <= height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;

            // printf(
            //    "l:%d/r:%d, lower:%d, level:%d, water:%d\n",
            //    l, r, lower, level, water);
        }

        return water;
    }
};

