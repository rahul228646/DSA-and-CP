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
