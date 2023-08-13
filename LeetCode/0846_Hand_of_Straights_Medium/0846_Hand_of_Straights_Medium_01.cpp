/*
 *  Results:    AC (43 ms [97.53%];  26.84 MB [80.30%])
 */


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> umap;

        if (hand.size() % groupSize)
            return false;

        sort(hand.begin(), hand.end());
        for (const auto &num : hand)
            umap[num]++;

        for (unsigned int i = 0; i < hand.size(); ++i) {
            if (umap[hand[i]] > 0) {
                for (unsigned int j = 0; j < groupSize; ++j) {
                    if (umap[hand[i] + j]-- <= 0)
                        return false;
                }
            }
        }

        return true;
    }
};

/*
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
==> [1,2,2,3,3,4,6,7,8]
*/

