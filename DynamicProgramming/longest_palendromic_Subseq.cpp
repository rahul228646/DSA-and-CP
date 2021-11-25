

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
