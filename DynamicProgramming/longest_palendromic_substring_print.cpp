
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), mx = 0, ans_start = 0, ans_end = 0;
        string ans;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int gap = 0; gap<n; gap++) {
            for(int i = 0, j = gap; j<n; i++, j++) {
                if(gap == 0) dp[i][j] = 1;
                else if(gap == 1) dp[i][j] = (s[i]==s[j]) ? 2 : 0;
                else {
                    if(s[i]==s[j] && dp[i+1][j-1] != 0) dp[i][j] = 2+dp[i+1][j-1];
                    else dp[i][j] = 0;
                }
                if(dp[i][j]>mx) {
                    mx = dp[i][j];
                    ans_start = i;
                    ans_end = j;
                }
            }
        }
        
        // for(auto i : dp) {
        //     for(auto j : i) cout<<j<<" ";
        //     cout<<endl;
        // }
        // cout<<x<<y<<endl;
        return s.substr(ans_start, (ans_end - ans_start + 1));
    }
};
    a b c c b c
a   1 0 0 0 0 0 
b   0 1 0 0 4 0 
c   0 0 1 2 0 0 
c   0 0 0 1 0 3 
b   0 0 0 0 1 0 
c   0 0 0 0 0 1 
      
    1 4
