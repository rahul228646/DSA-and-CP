// https://leetcode.com/problems/minimum-falling-path-sum/

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
// Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// brute force

class Solution {
public:

    vector<pair<int, int>> dir = {{1, 0}, {1, 1}, {1, -1}};
    int solve (vector<vector<int>>& mat, int i, int j, int n, int m) {
        if(i<0 || j<0 || i>=n || j>=m) return INT_MAX;
        if(i == n-1) return mat[i][j];
        int ans = INT_MAX;
        for(auto k : dir) ans = min(ans,solve(mat, i+k.first,  j+k.second, n, m));
        return mat[i][j]+ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = INT_MAX;
        for(int i = 0; i<n; i++) ans = min(ans, solve(mat, 0,  i, n, m)); 
        return ans;
    }
};

// memo

class Solution {
public:
    vector<vector<int>> dp;
    vector<pair<int, int>> dir = {{1, 0}, {1, 1}, {1, -1}};
    int solve (vector<vector<int>>& mat, int i, int j, int n, int m) {
        if(i<0 || j<0 || i>=n || j>=m) return INT_MAX;
        if(i == n-1) return mat[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int ans = INT_MAX;
        for(auto k : dir) ans = min(ans,solve(mat, i+k.first,  j+k.second, n, m));
        return dp[i][j] = mat[i][j]+ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = INT_MAX;
        dp = vector<vector<int>>(n+1, vector<int>(m+1, INT_MAX) );
        for(int i = 0; i<n; i++) ans = min(ans, solve(mat, 0,  i, n, m)); 
        return ans;
    }
};


// tabular or bottom up 
// Time : O(N^2) Space : O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = INT_MAX;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                int a = mat[i-1][j], b = INT_MAX, c = INT_MAX;
                if(j-1 >= 0) b = mat[i-1][j-1];
                if(j+1 < m) c = mat[i-1][j+1]; 
                mat[i][j] += min(a, min(b, c));
            }
        }
        for(auto i : mat[n-1]) ans = min(ans, i);
        return ans;
    }
};

