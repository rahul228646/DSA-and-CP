https://leetcode.com/problems/count-number-of-ways-to-place-houses/submissions/
// memoization

class Solution {
public:
    const int mod = 1000000007;
    
    int helper(int n, bool prevSpace, vector<vector<int>> &dp) {
        if(n == 1) return dp[n][prevSpace] = 1;
        if(dp[n][prevSpace] != -1) return dp[n][prevSpace];
        if(prevSpace) return dp[n][prevSpace] = (helper(n-1, true, dp)%mod + helper(n-1, false, dp)%mod)%mod;
        else
            return dp[n][prevSpace]  = helper(n-1, true, dp)%mod;
    }
    int countHousePlacements(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        long long int ans = 1LL*helper(n, true, dp) + helper(n, false, dp);
        return ((ans%mod)*(ans%mod))%mod;
    }
};

