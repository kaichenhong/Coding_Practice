/*
 *  Results:    AC (3 ms [94.60%];  13.6 MB [91.68%])
 */


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (unsigned int i = 2; i < cost.size(); ++i)
            cost.at(i) += std::min(cost.at(i-1), cost.at(i-2));
        return std::min(cost.at(cost.size()-1), cost.at(cost.size()-2));
    }
};

