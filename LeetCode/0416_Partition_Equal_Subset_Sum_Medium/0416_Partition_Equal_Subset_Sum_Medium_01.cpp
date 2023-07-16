/*
 *  Results:    AC (1062 ms [5.10%];  9.7 MB [93.96%])
 */


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int target = find_target_val(nums);

        if (target < 0)
            return false;

        dp.resize(target + 1);
        dp.at(0) = true;
        for (const auto &n : nums)
            for (int i = target; i >= n; --i)
                dp.at(i) = dp.at(i) | dp.at(i - n);

        return dp.at(target);
    }
private:
    inline int find_target_val(const vector<int> &nums) {
        int sum = 0;

        for (const auto &n : nums)
            sum += n;
        return (sum % 2 == 0) ? (sum / 2) : -1;
    }

    vector<bool> dp;
};

/*
   012345678901
---------------
1  110000000000
5  110000100000
11 110000100001
5  110000100001
*/

