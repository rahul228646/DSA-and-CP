count of total palendromic substring
// https://www.youtube.com/watch?v=XmSOWnL6T_I
// Time : O(n^2) Space : O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int gap = 0; gap<n; gap++) {
            for(int i = 0, j = gap; j<n; i++, j++) {
                if(i == j) dp[i][j] = true;
                else if(j == i+1) dp[i][j] = (s[i]==s[j]) ? true : false;
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j] = true;
                    else dp[i][j] = false;
                }
                (dp[i][j]) ? count++ : 0;
            }
        }
        return count;
    }
};

abccbc 
col represents end point and row represents start pont

        a   b   c    c    b     c
        0   1   2    3    4     5
 a  0   a   ab  abc  abcc abccb abccbc
 b  1       b   bc   bcc  bccb  bccbc
 c  2           c    cc   ccb   ccbc
 c  3                c    cb    cbc
 b  4                     b     bc
 c  5                           c
 
 
        a   b   c    c    b     c
        0   1   2    3    4     5
 a  0   t   f   f    f    f     f
 b  1       t   f    f    t     f
 c  2           t    t    f     f
 c  3                t    f     t
 b  4                     t     f
 c  5                           t




  
