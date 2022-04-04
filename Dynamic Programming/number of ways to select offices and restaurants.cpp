// https://leetcode.com/problems/number-of-ways-to-select-buildings/
// gives tle
class Solution {
public:
    long long dp[1000000][3][4]; // n - (0, 10^5), prev - (0, 1, 2(initially)), size - (0, 1, 2, 3)
    
    long long solve (string s, char prev, int n, int size) {
        if(size == 3) return 1;
        if(n == 0) return 0;
        if(dp[n][prev-'0'][size] != -1) return dp[n][prev-'0'][size];
        long long  op1 = 0;
        if(s[n-1] != prev) {
            op1 = solve(s, s[n-1], n-1, size+1);
        }
        long long op2 = solve(s, prev, n-1, size);  
        return dp[n][prev-'0'][size] = op1 + op2;
    }
    
    long long numberOfWays(string s) {
        memset(dp,-1, sizeof dp);
        return solve(s, '2', s.length(), 0);
    }
};
