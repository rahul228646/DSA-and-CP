// https://leetcode.com/problems/coin-change-2/
// memo
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &coins, int n, int amount) {
      
        if(n <= 0 && amount != 0) return 0;
        if(amount == 0) return 1;
        
        if(dp[n][amount] != -1) return dp[n][amount];
      
        if(coins[n-1] <= amount) {
            return dp[n][amount] = solve(coins, n, amount-coins[n-1])+solve(coins, n-1, amount);;
        }
        else {
            return dp[n][amount] = solve(coins, n-1, amount);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp = vector<vector<int>> (n+1, vector<int>(amount+1, -1));
        return solve(coins, n, amount);
    }
};

// tabular

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n+1, vector<int>(amount+1, 0));
        
        for(int i = 0; i<=n; i++) dp[i][0] = 1;  // ans = 1 if amount = 0
        
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=amount; j++) {
                if(coins[i-1]<=j) {
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount];
    }
};
