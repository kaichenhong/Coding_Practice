/*
 *  Results:    AC (0 ms [100.00%];  8.7 MB [73.79%])
 */


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for (unsigned int i = 0; i < digits.size(); ++i) {
            const int pos = (digits.size() - 1 - i);

            carry = plus_one_at_pos(digits, pos, carry);
        }
        if (carry)
            digits.insert(digits.begin(), carry);

        return digits;
    }
private:
    inline int plus_one_at_pos(vector<int> &digits, const int pos, const int carry) {
        const int res = (digits.at(pos) + carry);

        digits.at(pos) = res % 10;
        return (res / 10);
    }
};

