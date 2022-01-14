

class lpsDp {
public:
   int longestPalindromicSubsequenceHelper(string text1, string text2) {

       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, 0));
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

               }
           }
       }
       return dp[size1][size2];
   }
   int longestPalindromicSubsequence(string a) {
       string s = a;
       reverse(a.begin(), a.end());
       return longestPalindromicSubsequenceHelper(s, a);
   }
};

// gap startegy

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(), mx = 0;
        vector<vector<int>> dp (n, vector<int>(n, 0));
        for(int gap = 0; gap<n; gap++) {
            for(int i = 0, j = gap; j<n; i++, j++) {
                if(gap == 0)            
                    dp[i][j] =1;   
                else if(gap ==1 && s[i] == s[j])       
                    dp[i][j] = 2;
                else {
                    if(s[i]==s[j] && dp[i+1][j-1] != 0) dp[i][j] = 2+dp[i+1][j-1]; 
                    else  dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
                mx = max(mx, dp[i][j]);
            }
        } 
        // for(auto i : dp) {
        //     for(auto j : i) cout<<j<<" ";
        //     cout<<endl;
        // }

        return mx;
    }
};
