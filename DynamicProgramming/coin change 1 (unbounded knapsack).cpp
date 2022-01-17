// https://leetcode.com/problems/coin-change/

// memoization
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &coins, int n, int amount) {
      
        if(n <= 0 && amount != 0) return INT_MAX-1;
        if(amount == 0) return 0;
        if(dp[n][amount] != -1) return dp[n][amount];
      
        if(coins[n-1] <= amount) {
            int a = 1+solve(coins, n, amount-coins[n-1]); // each coin can be included any number of time to we are calling with n insteas of n-1
            int b = solve(coins, n-1, amount);
          
            if(a == b && (a == INT_MAX-1 || a == INT_MAX)) return dp[n][amount] = INT_MAX-1;
            else 
                return dp[n][amount] = min(a, b);
        }
        else {
            return dp[n][amount] = solve(coins, n-1, amount);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp = vector<vector<int>> (n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, n, amount);
        return (ans == INT_MAX || ans == INT_MAX-1) ? -1 : ans;
    }
};
