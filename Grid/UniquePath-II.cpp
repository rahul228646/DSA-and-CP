
https://leetcode.com/problems/unique-paths-ii/submissions/

// memoization or top down

class Solution {
    vector<vector<int>> dp;
public:
    int dfs(vector<vector<int>>& obstacleGrid, int i, int j, int n, int m) {
        if(i>n || i<0 || j>m || j<0 || obstacleGrid[i][j] == 1) 
            return 0;
        if(i == n && j == m) 
            return 1;
        if(dp[i][j] != -1) 
            return dp[i][j];
        return dp[i][j] = dfs(obstacleGrid, i+1, j, n, m) + dfs(obstacleGrid, i, j+1, n, m);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        dp = vector<vector<int>> (n+1, vector<int>(m+1, -1));
        return dfs(obstacleGrid, 0, 0, n-1, m-1);
    }
};

// tabular or bottom up

class Solution {

public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0));
        // If the starting cell has an obstacle, then simply return as there would be
        // no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Number of ways of reaching the starting cell = 1.
        dp[0][0] = 1;
        
        // initialising 1st col - if prev was visited and we don't encounter any obstacle on the current one then 1 else 0  
        for(int i = 1; i<n; i++) {
            dp[i][0] = (dp[i-1][0] && obstacleGrid[i][0] == 0) ? 1 : 0;
        }
           // initialising 1st row - if prev was visited and we don't encounter any obstacle on the current one then 1 else 0 
        for(int j = 1; j<m; j++) {
            dp[0][j] = (dp[0][j-1] && obstacleGrid[0][j] == 0) ? 1 : 0;
        }

        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
