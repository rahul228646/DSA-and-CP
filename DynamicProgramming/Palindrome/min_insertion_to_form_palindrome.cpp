


class Solution{
  public:
    int lcs (string a, string b, int n1, int n2) {
        vector<vector<int>> dp (n1+1, vector<int>(n2+1, 0));
        for(int i = 1; i<=n1; i++) {
            for(int j = 1; j<=n2; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
  
    int lps(string a) {
        int n = a.length();
        string b = a;
        reverse(b.begin(), b.end());
        return lcs(a, b, n, n);
    }
  
    int countMin(string a){
        return n-lps(a);
    }
};
