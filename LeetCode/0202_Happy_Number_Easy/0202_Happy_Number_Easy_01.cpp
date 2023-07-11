/*
 *  Results:    AC (0 ms [100.00%];  5.9 MB [89.53%])
 */


class Solution {
public:
    bool isHappy(int n) {
        int next_num = n;
        int next_next_num = calc_next_num(n);

        while ((next_next_num != 1) && (next_num != next_next_num)) {
            next_num = calc_next_num(next_num);
            next_next_num = calc_next_num(calc_next_num(next_next_num));
        }

        return (next_next_num == 1);
    }
private:
    inline int calc_next_num(int n) {
        int res = 0;
        while (n) {
            int val = n % 10;

            res += val * val;
            n = n / 10;
        }
        return res;
    }
};
/*
2
4
16
37
58 = 9+49
89 = 25+64
145 = 64+81
42 = 1+16+25
20
4
*/

