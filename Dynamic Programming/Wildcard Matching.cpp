https://leetcode.com/problems/wildcard-matching/submissions/
// gives TLE
class Solution {
public:
    int solve(string a, string b, int n, int m, vector<vector<int>> &dp) {
        if(n == 0 && m == 0) return true;
        if(m == 0) return false;
        if(n == 0) {
            for(int i = 0; i<m; i++) if(b[i]!='*') return false;
            return true;
        }
        if(dp[n][m] != -1) return dp[n][m];
        if(a[n-1] == b[m-1] || b[m-1] == '?') return dp[n][m] = solve(a, b, n-1, m-1, dp);
        if(a[n-1] != b[m-1] && b[m-1] != '*') return dp[n][m] = false;
        else {
            dp[n][m] = false;
            for(int i = 0; i<=n; i++) {
                 dp[n][m] = dp[n][m] || solve(a, b, n-i, m-1, dp);
            }
            return dp[n][m];
        }
    }
    bool isMatch(string a, string b) {
        int i = 0; 
        int n = a.length(), m = b.length();
        string s;
        bool star = false;
        while(i<m) {
            while(i<m && b[i] != '*') {
                s.push_back(b[i]);
                i++;
            }
            while(i<m && b[i] == '*') {
                star = true;
                i++;
            }
            if(star) {
                s.push_back('*');
                star = false;
            }
        }
        b = s;
        m = b.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return solve(a, b, n, m, dp);
    }
};

or
// gives memory limit exceded
class Solution {
public:
    int solve(string a, string b, int n, int m, vector<vector<int>> &dp) {
        if(n == 0 && m == 0) return true;
        if(m == 0) return false;
        if(n == 0) {
            for(int i = 0; i<m; i++) if(b[i]!='*') return false;
            return true;
        }
        if(dp[n][m] != -1) return dp[n][m];
        if(a[n-1] == b[m-1] || b[m-1] == '?') return dp[n][m] = solve(a, b, n-1, m-1, dp);
        if(a[n-1] != b[m-1] && b[m-1] != '*') return dp[n][m] = false;
        else {
             return dp[n][m] = solve(a, b, n-1, m, dp) || solve(a, b, n, m-1, dp);
        }
    }
    bool isMatch(string a, string b) {
        int i = 0; 
        int n = a.length(), m = b.length();
        string s;
        bool star = false;
        while(i<m) {
            while(i<m && b[i] != '*') {
                s.push_back(b[i]);
                i++;
            }
            while(i<m && b[i] == '*') {
                star = true;
                i++;
            }
            if(star) {
                s.push_back('*');
                star = false;
            }
        }
        b = s;
        m = b.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return solve(a, b, n, m, dp);
    }
};

// tabular
class Solution {
public:
    int solve(string a, string b, int n, int m, vector<vector<bool>> &dp) {
        dp[0][0] = true;
        for(int i = 1; i<=n; i++) {
            dp[i][0] = false;
        }
        bool flag = true;
        for(int i = 1; i<=m; i++) {
            if(b[i-1] != '*') flag = false;
            dp[0][i] = flag;
        }

        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(a[i-1] == b[j-1] || b[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (a[i-1] != b[j-1] && b[j-1] != '*') {
                    dp[i][j] = false;
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
    bool isMatch(string a, string b) {
        int i = 0; 
        int n = a.length(), m = b.length();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        return solve(a, b, n, m, dp);
    }
};

// space optimized
class Solution {
public:

    bool isMatch(string a, string b) {
        int i = 0; 
        int n = a.length(), m = b.length();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        vector<bool> prev(m+1, false), curr(m+1, false);
        
        prev[0] = true;  //dp[0][0] = true;
        
        // bool flag = true;
        // for(int i = 1; i<=m; i++) {
        //     if(b[i-1] != '*') flag = false;
        //     dp[0][i] = flag;
        // }
        
        bool flag = true;
        for(int i = 1; i<=m; i++) {
            if(b[i-1] != '*') flag = false;
            prev[i] = flag;
        }

        for(int i = 1; i<=n; i++) {
            
        // for(int i = 1; i<=n; i++) {
        //     dp[i][0] = false;
        // }

            curr[0] = false;
            for(int j = 1; j<=m; j++) {
                if(a[i-1] == b[j-1] || b[j-1] == '?') {
                    curr[j] = prev[j-1];
                }
                else if (a[i-1] != b[j-1] && b[j-1] != '*') {
                    curr[j] = false;
                }
                else {
                    curr[j] = prev[j] || curr[j-1];
                }
            }
            prev = curr;
        }
        return prev[m];
        
    }
};
