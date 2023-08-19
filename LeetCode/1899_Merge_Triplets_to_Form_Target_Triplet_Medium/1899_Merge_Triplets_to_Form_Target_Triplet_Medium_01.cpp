/*
 *  Results:    AC (389 ms [91.82%];  146.5 MB [42.53%])
 */


class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> buf(3, 0);

        for (const auto &src : triplets) {
            if (chk_can_be_selected(src, target) == false)
                continue;
            update_triplet(buf, src);
        }

        return (buf == target);
    }
private:
    inline void update_triplet(vector<int> &triplet, const vector<int> &src) {
        for (unsigned int i = 0; i < src.size(); ++i) {
            if (src[i] > triplet[i])
                triplet[i] = src[i];
        }
    }
    inline bool chk_can_be_selected(const vector<int> &triplet, const vector<int> &target) {
        for (unsigned int i = 0; i < target.size(); ++i) {
            if (triplet[i] > target[i])
                return false;
        }
        return true;
    }
};

