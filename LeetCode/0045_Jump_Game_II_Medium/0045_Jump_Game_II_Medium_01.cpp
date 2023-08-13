/*
 *  Results:    AC (3 ms [99.92%];  16.5 MB [63.37%])
 */


class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0, l = 0, r = 0;

        while (r < (nums.size() - 1)) {
            unsigned int farthest = r;

            for (unsigned int i = l; i <= r; ++i)
                farthest = max(farthest, i + nums[i]);

            l = r + 1;
            r = farthest;
            cnt++;
        }

        return cnt;
    }
};

