// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



// select min price day to buy and cal profit by subtracting it with the price of stock on subsequent days, while continue to update min price day

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minSoFar = p[0], profit = 0, n = p.size();
        for(int i = 1; i<n; i++) {
            profit = max(p[i] - minSoFar, profit);
            minSoFar = min(minSoFar, p[i]);
        } 
        return profit;
    }
};
