class Solution {
public:
    int solve(string s, string t, int n, int m, vector<vector<int>>& dp) {
        if(m == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n-1] == t[m-1]) {
            return dp[n][m] = solve(s, t, n-1, m-1, dp) + solve(s, t, n-1, m, dp); 
        }
        else {
             return dp[n][m] = solve(s, t, n-1, m, dp); 
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp (n+1, vector<int>(m+1, -1)); 
        return solve(s, t, n, m, dp);
    }
};

// tabular

class Solution {
public:
    int numDistinct(string s, string t) {
       int n = s.length(), m = t.length();
       vector<vector<long long unsigned int>> dp (n+1, vector<long long unsigned int>(m+1, 0)); 
        
       for(int i = 0; i<=n; i++) dp[i][0] = 1; // s is empty and t is not

       for (int i = 1; i <=n; ++i) {
           for (int j = 1; j <=m; ++j) {
               if(s[i-1] == t[j-1]) {
                   dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
               }
               else {
                   dp[i][j] =dp[i-1][j];

               }
           }
       }
        
       return dp[n][m];

    }
};

// space optimized

class Solution {
public:
    int numDistinct(string s, string t) {
       int n = s.length(), m = t.length(); 
       vector<long long unsigned int> prev(m+1, 0), curr(m+1, 0);
       for (int i = 1; i <=n; ++i) {
           prev[0] = 1; 
           for (int j = 1; j <=m; ++j) {
               if(s[i-1] == t[j-1]) {
                   curr[j] = prev[j] + prev[j-1];
               }
               else {
                   curr[j] = prev[j];

               }
           }
           prev = curr;
       }
        
       return prev[m];

    }
};
