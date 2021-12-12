/**
 *  LeetCode: 121. Best Time to Buy and Sell Stock (Easy)
 *
 *      Say you have an array for which the ith element is the price of a given stock on day i.
 *
 *      If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 *      Note that you cannot sell a stock before you buy one.
 *
 *
 *      Example:    1. [7,1,5,3,6,4] => 5
 *                      (Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *                      Not 7-1 = 6, as selling price needs to be larger than buying price.)
 *
 *                  2. [7,6,4,3,1] => 0
 *                      (In this case, no transaction is done, i.e. max profit = 0.)
 *
 *
 *
 *  Results:    AC (104 ms [93.69%];  93.3 MB [90.13%])
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = prices[0];

        for (size_t i = 0; i < prices.size(); ++i) {
            buy = std::min(prices[i], buy);
            profit = std::max((prices[i] - buy), profit);
        }

        return profit;
    }
};

