// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    vector<vector<int>> dp;
    int solve (vector<vector<int>>& grid, int n, int m, int i, int j) {
        if(i<0 || j<0 || i>=n || j>=m) return INT_MAX;
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(grid, n, m, i, j+1), solve(grid, n, m, i+1, j));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        return solve(grid, n, m,  0, 0);
    }
};
