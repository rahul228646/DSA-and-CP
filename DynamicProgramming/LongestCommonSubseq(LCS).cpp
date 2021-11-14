
class lcsMemo {
public:

   vector<vector<int>> dp;
   int longestCommonSubsequenceHelper(string t1, string t2, int n, int m) {
       if(n == 0 || m == 0)
           return 0;
       if(dp[n][m] != -1)
           return dp[n][m];

       if(t1[n-1] == t2[m-1])
           return dp[n][m] = (1+ longestCommonSubsequenceHelper(t1, t2, n-1, m-1));
       else {
           return dp[n][m] =
                   max(longestCommonSubsequenceHelper(t1, t2, n, m-1),  longestCommonSubsequenceHelper(t1, t2, n-1, m));
       }

   }
   int longestCommonSubsequence(string t1, string t2) {
       dp =  vector<vector<int>> (t1.length()+1, vector<int>(t1.length()+1, -1));
       return longestCommonSubsequenceHelper(t1, t2, t1.length(), t2.length());
   }
};

class lcsDp {
public:

   int longestCommonSubsequence(string t1, string t1) {
       int n = t1.length();
       int m = t2.length();
       
       vector<vector<int>> dp (n+1, vector<int>(m+1, 0));

       for (int i = 1; i <=n; ++i) {
           for (int j = 1; j <=m; ++j) {
               if(t1[i-1] == t2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

               }
           }
       }
       return dp[n][m];
   }
};
