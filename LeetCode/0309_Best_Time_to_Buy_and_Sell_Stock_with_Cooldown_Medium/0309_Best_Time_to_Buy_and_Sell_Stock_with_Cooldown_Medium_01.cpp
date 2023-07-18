/*
 *  Results:    AC (0 ms [100.00%];  11.0 MB [98.25%])
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy, sell = 0, cooldown = 0;
        int prev_buy = INT_MIN, prev_sell = 0, prev_cooldown = 0;

        prev_buy = 0 - prices.at(0);
        for (unsigned int i = 1; i < prices.size(); ++i) {
            buy = std::max(prev_cooldown - prices.at(i), prev_buy);
            sell = std::max(prev_buy + prices.at(i), prev_sell);
            cooldown = std::max(std::max(prev_buy, prev_sell), prev_cooldown);

            prev_buy = buy;
            prev_sell = sell;
            prev_cooldown = cooldown;
        }
        return sell;
    }
};
/*
* check the max profit when do "buy", "sell", "cooldown" operation at each price.
*        1, 2, 3, 0, 2
* --------------------
*  buy: -1,-1,-1, 1, 1
* sell:  0, 1, 2, 2, 3
* cool:  0, 0, 1, 2, 2
*/

