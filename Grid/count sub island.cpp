https://leetcode.com/problems/count-sub-islands/

// DFS

class Solution {
public:
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    bool flag = true;
    void solve(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int n, int m) {
        if(grid1[i][j] == 0) flag = false;
        grid2[i][j] = 0;
        for(auto k : dir) {
            if(i+k.first>=0 && j+k.second>=0 && i+k.first<n && j+k.second<m && grid2[i+k.first][j+k.second] == 1) 
                solve(grid1, grid2, i+k.first, j+k.second, n, m);
        }
        return;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid1[i][j] == 1 && grid2[i][j] == 1) {
                    flag = true;
                    solve(grid1, grid2, i, j, n, m);
                    if(flag) ans++;
                }
            }
        }
        
        return ans;
    }
};



