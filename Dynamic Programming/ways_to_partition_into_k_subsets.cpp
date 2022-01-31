// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

// The previous n – 1 elements are divided into k partitions, i.e S(n-1, k) ways. 
// Put this nth element into one of the previous k partitions. So, count = k * S(n-1, k)
  
// The previous n – 1 elements are divided into k – 1 partitions, i.e S(n-1, k-1) ways. 
// Put the nth element into a new partition ( single element partition).So, count = S(n-1, k-1)
  
// Total count = k * S(n-1, k) + S(n-1, k-1).


// time : O(2^N) space : O(N) stack size

int countP(int n, int k) {
  if (n == 0 || k == 0 || k > n)
     return 0;
  if (k == 1 || k == n)
      return 1;
  // S(n+1, k) = k*S(n, k) + S(n, k-1)
  return  k*countP(n-1, k) + countP(n-1, k-1);
}


int countDp(int n, int k) {
  vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
  for(int i = 1; i<=n; i++) {
    for(int j = 1; i<=k; j++) {
      if(j == 1 || j == i) dp[i][j] = 1;
      else dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
    }
  }
  return dp[n][k];
}
