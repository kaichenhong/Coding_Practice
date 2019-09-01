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
 *  Results:    AC (4 ms [98.31%];  9.5 MB [93.58%])
 *              AC (8 ms [67.17%];  9.3 MB [100.00%])
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)   return 0;

        // draw a table, write down "all the results", think how to simplfy and do fast. (NP DP)
        int minPrice = prices[0], profit = 0, maxProfit = 0;
        for (int i = 1; i < int(prices.size()); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                continue;
            }
            profit = prices[i] - minPrice;
            if (profit > maxProfit)
                maxProfit = profit;
        }
        return maxProfit;
    }
};