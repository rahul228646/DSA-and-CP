// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
                int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};

// or

class Solution {
public:
     vector<vector<int>> dp;
    int fee = 0;
    int solve (vector<int>& p, int n, bool bought, int index) {
        if(index>=n) return 0;
        if(dp[bought][index] != -1) return dp[bought][index];
        if(bought) {
            return dp[bought][index] = max(p[index]-fee+solve(p, n, false, index+1), solve(p, n, true, index+1));
        }
        else {
            return dp[bought][index] = max(-p[index]+solve(p, n, true, index+1), solve(p, n, false, index+1));
        }
    }
    int maxProfit(vector<int>& p, int f) {
        int n = p.size();
        fee = f;
        dp = vector<vector<int>> (2, vector<int>(n+1, -1));
        return solve(p, n, false, 0);
    }
};
