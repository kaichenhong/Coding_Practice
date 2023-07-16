/*
 *  Results:    AC (3 ms [100.00%];  9.6 MB [97.68%])
 */


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int target = find_target_val(nums);

        if (target < 0)
            return false;

        dp_bits[0] = 1;
        for (const auto &n : nums)
            dp_bits |= dp_bits << n;

        return dp_bits[target];
    }
private:
    inline int find_target_val(const vector<int> &nums) {
        int sum = 0;

        for (const auto &n : nums)
            sum += n;
        return (sum % 2 == 0) ? (sum / 2) : -1;
    }

    // 10001 <== (100 * 200) / 2 + 1
    bitset<10001> dp_bits;
};

/*
   1 5 11 5
----------------------
2109876543210987654321
----------------------
0000000000000000000001
0000000000000000110001
0000011000110000110001
1100011000111000110001

1100011000011000100000
0000011000110000110001
*/

