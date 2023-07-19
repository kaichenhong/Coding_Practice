/*
 *  Results:    AC (12 ms [84.27%];  6.9 MB [98.16%])
 */


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        dp.resize(amount + 1);
        dp.at(0) = 1;
        for (const int &coin : coins)
            for (unsigned int i = coin; i <= amount; ++i)
                dp.at(i) += dp.at(i - coin);

        return dp.at(amount);
    }
private:
    vector<int> dp;
};
/*
*  | 0  1  2  3  4  5
* -------------------
* 1| 1  1  2  2  3  4
* 2| 1  0  1  0  1  1(0+1)
* 5| 1  0  0  0  0  1
* -------------------
* if only have 2 & 5
* -------------------
* 2| 1  0  1  0  1  1
* 5| 1  0  0  0  0  1
* -------------------
* if only have 1 & 2
* -------------------
* 1| 1  1  1  1  1  1
* 2| 1  1  2  2  3  3
*/

