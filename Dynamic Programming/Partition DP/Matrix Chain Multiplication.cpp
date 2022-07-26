https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

// time : O(N^3) space : O(N^2) + stack space O(N)
int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if(i == j) return 0;
    int mn = INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k = i; k<j; k++) {
        int steps = arr[i-1]*arr[k]*arr[j] + solve(arr, i, k, dp) + solve(arr, k+1, j, dp);
        mn = min(mn, steps);
    }
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int N){
    // Write your code here.
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    return solve(arr, 1, N-1, dp);
}


// time : O(N^3) space : O(N^2)
int matrixMultiplication(vector<int> &arr, int n){
    // Write your code here.
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = n-1; i>=1 ;i--) {
        for(int j = i+1; j<n; j++) {
            int mn = INT_MAX;
            for(int k = i; k<j; k++) {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mn = min(mn, steps); 
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][n-1];
}
