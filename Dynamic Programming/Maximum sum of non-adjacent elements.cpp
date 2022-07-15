// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

int solve(vector<int> &a, int n, bool prev, vector<vector<int>> &dp) {
    if(n == 0) return 0;
    if(dp[n][prev]!=-1) return dp[n][prev];
    if(prev) {
        return  dp[n][prev] = solve(a, n-1, false, dp);
    }
    else {
        return dp[n][prev] = max(solve(a, n-1, false, dp), a[n-1] + solve(a, n-1, true, dp));
    }
}

int maximumNonAdjacentSum(vector<int> &a){
    vector<vector<int>> dp(a.size()+1, vector<int>(2, -1));
    return solve(a, a.size(), false, dp);
}

or
  
int solve(vector<int> &a, int n, vector<int> &dp) {
    if(n<0) return 0;
    if(n == 0) return a[0];
    if(dp[n]!=-1) return dp[n];
   
    return dp[n] = max(solve(a, n-1, dp), a[n] + solve(a, n-2, dp));
}

int maximumNonAdjacentSum(vector<int> &a){
    vector<int> dp(a.size(), -1);
    return solve(a, a.size()-1, dp);
}

or
  
int maximumNonAdjacentSum(vector<int> &a){
    int n = a.size();
    if(n == 1) return a[0];
    vector<int> dp(a.size(), 0);
    dp[0] = a[0];
    dp[1] = max(a[1], a[0]);
    for(int i = 2; i<n; i++) {
       dp[i] = max(a[i] + dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}
