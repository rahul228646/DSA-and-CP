// memoizarion 
class Solution {
public:
    int solve(string a, string b, int n, int m, vector<vector<int>> &dp) {
        if(n == 0 && m == 0) return 0;
        if(n == 0) return m;
        if(m == 0) return n;
        if(dp[n][m] != -1) return dp[n][m];
        if(a[n-1] == b[m-1]) {
            return dp[n][m] = solve(a, b, n-1, m-1, dp);
        }
        else {
            return dp[n][m] = 1 + min (solve(a, b, n-1, m-1, dp), 
                            min(
                                solve(a, b, n-1, m, dp),
                                solve(a, b, n, m-1, dp)
                               ));
        }
        
    }
    int minDistance(string a, string b) {
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(a, b, n, m, dp);
    }
};

// tabular
class Solution {
public:
// we will modify t1 to make it equal to t2
    int minDistance(string t1, string t2) {
        int n = t1.length(), m = t2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 0; i<=n; i++) dp[i][0] = i; 
        // if t2 is empty the we'll have to delete i characters from t1 to make it equla to t2
        for(int i = 0; i<=m; i++) dp[0][i] = i; 
        // if t1 is empty, only option is to insert all characters of t2
        
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(t1[i-1] == t2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                    // copy previous answer
                }
                else {
                     dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    // we have three option 
                    //  1. delete from t1 that is dp[i-1][j]
                    //  2. inset into t1 that is dp[i][j-1]
                    //  3. replace from t1 that is dp[i-1][j-1]
                        
                }
            }
        }
        return dp[n][m];
    }
};


