

    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        // row represenst array size and column represenst sum's
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
        // ans will be true if sum = 0 (null subset) i.e dp[i][0] will all be i
        for(int i = 0; i<n; i++) dp[i][0] = true;
        
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=sum; j++) {
              // if arr[n-1] <= current sum i.e column
                if(arr[i-1] <= j) {
                  // two choice either inc val of arr or exculde it
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }


    vector<vector<bool>> dp;
    bool solve(int n, int arr[], int sum) {
        if(sum == 0) return true;
        if(n<=0) return false;
        if(dp[n][sum]) return dp[n][sum];
        if(arr[n-1] <= sum) {
            return dp[n][sum] = solve(n-1, arr, sum) || solve(n-1, arr, sum - arr[n-1]);
        }
        return dp[n][sum] = solve(n-1, arr, sum);
        
    }
    bool isSubsetSum(int n, int arr[], int sum){
        dp = vector<vector<bool>> (n+1, vector<bool> (sum+1, false));
        return solve(n, arr, sum);
       
    }
