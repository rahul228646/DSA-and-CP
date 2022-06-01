// https://leetcode.com/problems/coin-change/

// memoization
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amount, int n) {
        if(t == 0) return 0;
        if(n == 0) return INT_MAX-1;
        if(dp[n][amount] != -1) return dp[n][amount];
        if(coins[n-1] <= amount)
            return dp[n][amount] = min(1 + solve(coins, amount-coins[n-1], n), solve(coins, amount, n-1));
        else 
            return dp[n][amount] = solve(coins, amount, n-1);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp = vector<vector<int>> (n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, n);
        return (ans == INT_MAX || ans == INT_MAX-1) ? -1 : ans;
    }
};

// tabular

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp (n+1, vector<int>(amount+1, 0));
        
        dp[0][0] = INT_MAX-1;
        for(int i = 1; i<=n; i++) dp[i][0] = 0; // ans is 0 if amount == 0;
        for(int i = 1; i<=amount; i++) dp[0][i] = INT_MAX-1; 
        // ans is -1 for n == 0 but since we will be doing min(1+including,  exluding) so we will keep it as INT_MAX-1 and put a check for it at the end;
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=amount; j++) {
                if(coins[i-1]<=j) {
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (dp[n][amount] == INT_MAX || dp[n][amount]  == INT_MAX-1) ? -1 : dp[n][amount];
    }
};
