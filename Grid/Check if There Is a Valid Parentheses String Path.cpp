
https://leetcode.com/contest/weekly-contest-292/problems/check-if-there-is-a-valid-parentheses-string-path/

class Solution {
public:
    int dp[101][101][1001];
    bool dfs (vector<vector<char>>& grid, int open, int i, int j) {
        if(i>=grid.size() || j >=grid[0].size()) return false;
        if(grid[i][j] == '(') open++;
        else open--;
        if(open < 0) return false;
        if(dp[i][j][open] != -1) return dp[i][j][open];
        if(i == grid.size()-1 && j == grid[0].size()-1) {
            if(open == 0) return true;
            else return false;
        }
        
        return dp[i][j][open] = dfs(grid, open, i+1, j) || dfs(grid, open, i, j+1);
            
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0, 0);
    }
};
