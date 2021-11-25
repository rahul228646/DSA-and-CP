

bool subsetSum(vector<int> arr, int sum) {
  int n = arr.size();
  vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
  dp[0][0] = true;
  for(int i = 1; i<=n; i++) {
    for(int j = 1; j<=sum; i++) {
      if(arr[i-1]<=j) {
        dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
      }
      else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][sum];
}

bool equalSum(vector<int> arr) {
  int sum = 0;
  for(auto i : arr) sum += i;
  if(sum % 2 != 0) return false;
  return subsetSum(arr, sum);
}
