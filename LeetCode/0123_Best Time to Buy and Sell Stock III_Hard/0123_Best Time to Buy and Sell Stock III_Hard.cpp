/**
 *  LeetCode: 123. Best Time to Buy and Sell Stock III (Hard)
 *
 *      Say you have an array for which the ith element is the price of a given stock on day i.
 *
 *      Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 *      Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 *
 *      Example:    1. [3,3,5,0,0,3,1,4] => 6;      
 *                      Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 *                      Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 *
 *                  2. [1,2,3,4,5] => 4;
 *                      Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *                      Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *                      engaging multiple transactions at the same time. You must sell before buying again.
 *
 *
 *
 *  Results:    AC (4 ms [98.24%];  9.8 MB [35.71%])
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = int(prices.size());
        if (size == 0 || size == 1)   return 0;

        // DP and NP, draw a table, write down "all the results", think and find how to solve this problem.
        int max_Profit;
        int leftBuffer[size] = {0}, localMin = prices[0];
        max_Profit = INT_MIN;
        for (int i = 1; i < size; ++i) {
            if (prices[i] < localMin)
                localMin = prices[i];
            int cur_profit = prices[i] - localMin;
            if (cur_profit > max_Profit)    
                max_Profit = cur_profit;
            leftBuffer[i] = max_Profit;
        }

        int rightBuffer[size] = {0}, localMax = prices[size-1];
        max_Profit = INT_MIN;
        for (int i = size-2; i >= 0; --i) {
            if (prices[i] > localMax)
                localMax = prices[i];
            int cur_profit = localMax - prices[i];
            if (cur_profit > max_Profit)    
                max_Profit = cur_profit;
            rightBuffer[i] = max_Profit;
        }

        max_Profit = INT_MIN;
        for (int i = 0; i < size; ++i) {
            int result = leftBuffer[i] + rightBuffer[i];
            if (result > max_Profit)
                max_Profit = result;
        }
        return max_Profit;
    }
};


// AC (4 ms [98.24%];  9.8 MB [35.71%])