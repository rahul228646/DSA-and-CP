
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve

// peak valley approach (when slope (diff b/w consecutive elements) is +ve add the diff to profit)

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int prof = 0;
        for(int i = 1; i<p.size(); i++) {
            if(p[i]-p[i-1] > 0) {
                prof += p[i]-p[i-1];
            }
        }
        return prof;
    }
};
