// https://www.geeksforgeeks.org/find-if-string-is-k-palindrome-or-not/

// Since given string is compared with its reverse, we will do at most N deletions from first string and N deletions from second string 
// to make them equal. Therefore, for a string to be k-palindrome, 2*N <= 2*K should hold true.
  
bool solve(string s1, string s2, int k) {
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = 1; i<=n; i++) {
            dp[i][0] = i;
            dp[0][i] = i;
        }
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n]<=2*k;
    }
    int kPalindrome(string str, int n, int k) {
        string s = str;
        reverse(s.begin(), s.end());
        return solve(str,s,k);
    }

    a b c e d c b a
  0 1 2 3 4 5 6 7 8 
a 1 0 1 2 3 4 5 6 7 
b 2 1 0 1 2 3 4 5 6 
c 3 2 1 0 1 2 3 4 5 
d 4 3 2 1 2 1 2 3 4 
e 5 4 3 2 1 2 3 4 5 
c 6 5 4 3 2 3 2 3 4 
b 7 6 5 4 3 4 3 2 3 
a 8 7 6 5 4 5 4 3 2 
      
