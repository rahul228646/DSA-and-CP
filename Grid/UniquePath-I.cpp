
https://leetcode.com/problems/unique-paths/

// top down or memoization
class Solution {
    vector<vector<int>> dp;
public:
    int dfs (int i, int j, int n, int m) {
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(i == n-1 || j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = dfs(i+1, j, n, m) + dfs(i, j+1, n, m);
    }
    int uniquePaths(int n, int m) {
        dp = vector<vector<int>> (n+1, vector<int>(m+1, -1));
        return dfs(0, 0, n, m);
    }
};

// bottom up

class Solution {
public:
 
    int uniquePaths(int n, int m) {
        // dp stores unique paths where i stands for down and j stands for right
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = n-1; i>=0; i--) {
            for(int j = m-1; j>=0; j--) {
                // if we are on the last cloumn or row then we cannot go any where else beside going staright to the target therefore unique path is 1
                // if i==n-1 && j==m-1 then we have already reached the target therefore unique path is 1
                if(i == n-1 || j == m-1) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    // either go down or right
                }
            }
           
        }
        return dp[0][0];
    }
};
