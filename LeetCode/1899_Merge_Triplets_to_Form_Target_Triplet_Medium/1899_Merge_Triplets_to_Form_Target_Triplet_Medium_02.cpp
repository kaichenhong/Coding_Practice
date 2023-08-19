/*
 *  Results:    AC (369 ms [98.96%];  146.3 MB [80.97%])
 */


class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unsigned int res_mask = 0;

        for (const auto &src : triplets) {
            unsigned int mask = 0;

            if (chk_can_be_selected(src, target, mask) == false)
                continue;
            res_mask |= mask;
            if (res_mask == 0b111)
                return true;
        }

        return false;
    }
private:
    inline bool chk_can_be_selected(const vector<int> &triplet, const vector<int> &target, unsigned int &mask) {
        for (unsigned int i = 0; i < target.size(); ++i) {
            if (triplet[i] > target[i])
                return false;
            if (triplet[i] == target[i])
                mask |= (1U << i);
        }
        return true;
    }
};

