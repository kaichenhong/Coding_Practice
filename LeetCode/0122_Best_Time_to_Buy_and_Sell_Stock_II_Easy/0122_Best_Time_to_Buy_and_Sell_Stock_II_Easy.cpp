/**
 *  LeetCode: 122. Best Time to Buy and Sell Stock II (Easy)
 *
 *      Say you have an array for which the ith element is the price of a given stock on day i.
 *
 *      Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 *
 *      Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 *
 *      Example:    1. [7,1,5,3,6,4] => 7 
 *                      (Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *                      Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.)
 *
 *                  2. [1,2,3,4,5] => 4
 *                      (Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *                      Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *                      engaging multiple transactions at the same time. You must sell before buying again.)
 *
 *                  3. [7,6,4,3,1] => 0
 *                      (In this case, no transaction is done, i.e. max profit = 0.)
 *
 *
 *
 *  Results:    AC (4 ms [98.03%];  9.4 MB [100.00%])
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)   return 0;

        // draw a table, write down "all the results", think how to simplfy and do fast. (NP DP)
        int minPrice = prices[0], profit = 0, maxProfit = 0, totalProfit = 0;
        for (int i = 1; i < int(prices.size()); ++i) {
            profit = prices[i] - minPrice;
            if (profit < maxProfit) {
                totalProfit += maxProfit;
                maxProfit = 0;
                minPrice = prices[i];
            }
            else {
                maxProfit = profit;
            }
        }
        return maxProfit+totalProfit;;
    }
};