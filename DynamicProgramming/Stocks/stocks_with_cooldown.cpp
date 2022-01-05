// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

class Solution {
public:
    vector<vector<int>> dp;
    int solve (vector<int>& p, int n, bool bought, int index) {
        if(index>=n) return 0;
        if(dp[bought][index] != -1) return dp[bought][index];
        if(bought) {
            return dp[bought][index] = max(p[index]+solve(p, n, false, index+2), solve(p, n, true, index+1));
        }
        else {
            return dp[bought][index] = max(-p[index]+solve(p, n, true, index+1), solve(p, n, false, index+1));
        }
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        dp = vector<vector<int>> (2, vector<int>(n+1, -1));
        return solve(p, n, false, 0);
    }
};

or

// Time Complexity: O(n)
// Space Complexity: O(1)
  
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // There are only 1 or fewer days to trade stocks, so then we cannot make a profit by buying and
        // selling stocks, so we don't buy or sell (nor do we have the days to here XD),
        // so we return 0
        if(n<=1)
            return 0;
        
        // These variable will be used to implement the DP Sliding Window Technique
        int prevNoStock, prevInHand, prevSold;
        int nextNoStock, nextInHand, nextSold;
        
        prevNoStock = 0;
        prevInHand = -prices[0];    // Here we buy a stock on the very first day and have not sold it, yet
        prevSold = 0;
        
        for(int i=1; i<n; ++i)
        {
            // We have no stock today if we:
            // 1. Had no stock yesterday also, and we didn't do anything about it
            // 2. We sold a stock yesterday
            nextNoStock = max(prevNoStock, prevSold);
            
            // We have a stock in hand today if we:
            // 1. Had a stock in hand yesterday as well, and we didn't do anything about it
            // 2. Had no stock yesterday but we bought a stock today
            nextInHand = max(prevInHand, prevNoStock - prices[i]);  // We subtract prices[i] as we bought a stock
            
            // We have sold a stock today, if we:
            // Only had a stock in hand yesterday and we sold it today
            nextSold = prevInHand + prices[i];  // We add prices[i] as we sold a stock
            
            prevNoStock = nextNoStock;
            prevInHand = nextInHand;
            prevSold = nextSold;
            
        }

        return max(nextNoStock, nextSold);
    }
};
