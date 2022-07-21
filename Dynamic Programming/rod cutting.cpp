

Time : O(2^N) Space : O(stack space 2^N) 
  
int solve(vector<int> &p, int n, int len){
    if(n <= 0 || len<0) return 0;
    if(len<=n) {
         return max(p[len-1]+solve(p, n-len, len), solve(p, n,len-1));
    } 
    else {
        return solve(p, n, len-1);
    }
}

// memoization

Time : O(N^2) Space : O(N^2 + stack space N) 
int solve(vector<int> &p, int n, int len, vector<vector<int>> &dp){
    if(n <= 0 || len<=0) return 0;
    if(dp[len][n] != -1) return dp[len][n];
    if(len<=n) {
         return dp[len][n] = max(p[len-1]+solve(p, n-len, len, dp), solve(p, n, len-1, dp));
    } 
    else {
        return dp[len][n] = solve(p, n, len-1, dp);
    }
}


int cutRod(vector<int> &p, int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(p, n, n, dp);
}

// tabulation

Time : O(N^2) Space : O(N^2) 
  
int cutRod(vector<int> &p, int n){
    // cut len, rod len
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(i<=j) {
                dp[i][j] = max(p[i-1] + dp[i][j-i], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}

// space optimized

Time : O(N^2) Space : O(N) 
  
int cutRod(vector<int> &p, int n){
    // cut len, rod len
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(i<=j) {
                curr[j] = max(p[i-1] + curr[j-i], prev[j]);
            }
            else {
                curr[j] = prev[j];
            }
            prev = curr;
        }
    }
    return prev[n];
}




